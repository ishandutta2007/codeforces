#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#define free _free
using namespace std;

const int maxn = 2e5;

int cnt_car, cnt_man, cnt_house;

struct Car {
  int id;
  long long free;
  bool operator < (const Car &b) const {
    // for pq
    return free != b.free ? free > b.free : id > b.id;
  }
};

priority_queue<Car> avai[maxn];

struct Man {
  long long time;
  int start, end;
};

queue<Man> wait;

struct Message {
  int type;  // 0 for car, 1 for man
  long long time;
  int x, y;  // id, pos; a, b
  bool operator < (const Message &b) const {
    // for pq
    return time != b.time ? time > b.time : type > b.type;
  }
};

priority_queue<Message> msg;
set<int> pos;

void AddCar(int id, int p, long long time) {
  avai[p].push((Car){id, time});
  pos.insert(p);
}

int FindLeft(int i) {
  auto j = pos.upper_bound(i);
  if (j == pos.begin()) {
    return -1;
  }
  return *(--j);
}

int FindRight(int i) {
  auto j = pos.lower_bound(i);
  if (j == pos.end()) {
    return -1;
  }
  return *j;
}

void DoOnce(long long time) {
  Man u = wait.front();
  wait.pop();
  int p1 = FindLeft(u.start), p2 = FindRight(u.start);
  int p;
  if (p1 == -1) {
    p = p2;
  } else if (p2 == -1) {
    p = p1;
  } else if (u.start - p1 < p2 - u.start) {
    p = p1;
  } else if (u.start - p1 > p2 - u.start) {
    p = p2;
  } else if (avai[p2].top() < avai[p1].top()) {
    p = p1;
  } else {
    p = p2;
  }

  Car v = avai[p].top();
  avai[p].pop();
  if (avai[p].empty()) {
    pos.erase(p);
  }
  printf("%d %lld\n", v.id + 1, time + abs(u.start - p) - u.time);
  msg.push((Message){0, time + abs(u.start - p) +
        abs(u.end - u.start), v.id, u.end});
}

int main(void) {
  scanf("%d%d%d", &cnt_house, &cnt_car, &cnt_man);
  for (int i = 0; i < cnt_car; ++i) {
    int x;
    scanf("%d", &x);
    AddCar(i, x - 1, -1);
  }
  for (int i = 0; i < cnt_man; ++i) {
    long long t;
    int a, b;
    scanf("%lld%d%d", &t, &a, &b);
    --a; --b;
    msg.push((Message){1, t, a, b});
  }
  while (!msg.empty()) {
    Message u = msg.top();
    msg.pop();
    if (u.type == 0) {
      AddCar(u.x, u.y, u.time);
      if (!msg.empty() && msg.top().type == 0 &&
          msg.top().time == u.time) {
        continue;
      }
    } else {
      wait.push((Man){u.time, u.x, u.y});
    }
    while (!pos.empty() && !wait.empty()) {
      DoOnce(u.time);
    }
  }
  return 0;
}