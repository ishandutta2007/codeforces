#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int arrangement[n][m];
    map<int, vector<int>> groups;
    set<int> sightvalues;
    for (int i = 0; i < n*m; i++) {
      int sight;
      cin >> sight;
      groups[sight].push_back(i);
      sightvalues.insert(sight);
    }
    int seat = 0;
    for (int a: sightvalues) {
      vector<int> people = groups[a];
      int i = 0;
      while (i < people.size()) {
        // insert lowest m - seat % m people;
        int available = m - (seat % m);
        //cout << i << " " << available << endl;
        if (available <= people.size()-i) {
          for (int j = available; j > 0; j--) {
            int used_seat = seat + j-1;
            arrangement[used_seat/m][used_seat % m] = people[i];
            i++;
          }
          seat += available;
        }
        else {
          int update = people.size() - i;
          //cout << "HEY" << update << endl;
          for (int j = update; j > 0; j--) {
            int used_seat = seat + j-1;
            arrangement[used_seat/m][used_seat % m] = people[i];
            //cout << used_seat << endl;
            i++;
          }
          seat += update;
        }
      }
      /*reverse(people.begin(), people.end());
      for (int person: people) {
        arrangement[seat/m][seat % m] = person;
        //cout << seat/m << " " << seat % m << " " << person << endl;
        seat++;
      }*/
    }

    /*
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < m; i++) {
        cout << k << " " << i << " " << arrangement[k][i] << endl;
      }
    }
    */

    int ans = 0;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
          if (arrangement[k][i] < arrangement[k][j]) {
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
}