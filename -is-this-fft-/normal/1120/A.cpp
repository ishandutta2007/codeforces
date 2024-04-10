#include <iostream>
#include <set>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 5e5 + 5;

int arr [MAX_N];
int req [MAX_N];

int main () {
  int m, K, n, s;
  cin >> m >> K >> n >> s;

  set<pair<int, int>> freepos; // <value, position>
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    freepos.insert(make_pair(arr[i], i));
  }

  for (int i = 0; i < s; i++) {
    cin >> req[i];
  }

  set<pair<int, int>> takpos; // <position, corresp. req>
  for (int i = 0; i < s; i++) {
    auto it = freepos.lower_bound(make_pair(req[i], -1));
    if (it == freepos.end()) failure();
    if (it->first != req[i]) failure();

    int pos = it->second;
    freepos.erase(it);
    takpos.insert(make_pair(pos, i));
  }

  while (true) {
    int curl = takpos.begin()->first;
    int curr = takpos.rbegin()->first;
    // cerr << curl << " " << curr << endl;

    // can we turn the current thing into a legal segment?
    if (curr - curl + 1 >= K) {
      // we have to delete things in the middle and some after
      int cntbef = curl / K;
      int cntaft = (m - curr - 1) / K;
      if (cntbef + cntaft + 1 >= n) {
        int segst = curl - curl % K;
        int segen = curr;
        
        set<int> todel;
        for (int i = segst; i <= segen; i++) {
          todel.insert(i);
        }
        for (auto pr : takpos) {
          todel.erase(pr.first);
        }
        while (segen - segst + 1 - (int) todel.size() < K) {
          todel.erase(todel.begin());
        }

        cout << (int) todel.size() << '\n';
        for (auto p : todel) {
          cout << p + 1 << " ";
        }
        cout << '\n';
        return 0;
      }
    } else {
      // we can maybe delete some before?
      int segst = curl - curl % K;
      int segen = max(curr, segst + K - 1);
      int cntbef = segst / K;
      int cntaft = (m - segen - 1) / K;
      if (cntbef + cntaft + 1 >= n) {
        set<int> todel;
        for (int i = segst; i <= segen; i++) {
          todel.insert(i);
        }
        for (auto pr : takpos) {
          todel.erase(pr.first);
        }
        while (segen - segst + 1 - (int) todel.size() < K) {
          todel.erase(todel.begin());
        }

        cout << (int) todel.size() << '\n';
        for (auto p : todel) {
          cout << p + 1 << " ";
        }
        cout << '\n';
        return 0;
      }      
    }

    // if we didn't exit above, move the current segment
    pair<int, int> lreq = *takpos.begin();
    takpos.erase(lreq);
    auto it = freepos.lower_bound(make_pair(req[lreq.second], -1));
    if (it == freepos.end()) failure();
    if (it->first != req[lreq.second]) failure();

    int pos = it->second;
    freepos.erase(it);
    takpos.insert(make_pair(pos, lreq.second));
  }
}