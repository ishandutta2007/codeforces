#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 7e3 + 5;

int n;
vector<int> ricks;
vector<int> mortys;

int rick_w [MAX_N]; // -1 - lose, 1 - win, 0 - loop
int morty_w [MAX_N];

int has_r_l [MAX_N];
int has_m_l [MAX_N];
int cnt_r_w [MAX_N];
int cnt_m_w [MAX_N];

void mark_rick_lose (int state) {
  rick_w[state] = -1;
  for (int m : mortys) {
    has_r_l[(state - m + n) % n] = 1;
  }
}

void mark_morty_lose (int state) {
  morty_w[state] = -1;
  for (int r : ricks) {
    has_m_l[(state - r + n) % n] = 1;
  }
}

void mark_rick_win (int state) {
  rick_w[state] = 1;
  for (int m : mortys) {
    cnt_r_w[(state - m + n) % n] += 1;
  }
}

void mark_morty_win (int state) {
  morty_w[state] = 1;
  for (int r : ricks) {
    cnt_m_w[(state - r + n) % n] += 1;
  }
}


int main () {
  cin >> n;

  int rc;
  cin >> rc;
  ricks = vector<int> (rc);
  for (int i = 0; i < rc; i++) {
    cin >> ricks[i];
  }

  int mc;
  cin >> mc;
  mortys = vector<int> (mc);
  for (int i = 0; i < mc; i++) {
    cin >> mortys[i];
  }

  mark_rick_lose(0);
  mark_morty_lose(0);

  while (true) {
    int flag = 0;
    for (int i = 1; i < n; i++) {
      if (morty_w[i] == 0) {
        if (has_r_l[i]) {
          mark_morty_win(i);
          flag = 1;
        }

        if (cnt_r_w[i] == mc) {
          mark_morty_lose(i);
          flag = 1;
        }
      }

      if (rick_w[i] == 0) {
        if (has_m_l[i]) {
          mark_rick_win(i);
          flag = 1;
        }
      
        if (cnt_m_w[i] == rc) {
          mark_rick_lose(i);
          flag = 1;
        }
      }
    }
    if (!flag) {
      break;
    }
  }

  for (int i = 1; i < n; i++) {
    if (rick_w[i] == 1) {
      cout << "Win ";
    } else if (rick_w[i] == 0) {
      cout << "Loop ";
    } else {
      cout << "Lose ";
    }
  }
  cout << '\n';

  for (int i = 1; i < n; i++) {
    if (morty_w[i] == 1) {
      cout << "Win ";
    } else if (morty_w[i] == 0) {
      cout << "Loop ";
    } else {
      cout << "Lose ";
    }
  }
  cout << '\n';
}