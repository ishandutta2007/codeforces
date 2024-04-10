#include <bits/stdc++.h>

using namespace std;


int main()
{
  std::mt19937 rnd((unsigned) time(NULL));

  int T;
  cin >> T;

  while(T--) {
    int N, A[100];
    cin >> N;

    for(int i = 0; i < N; i++) {
      cin >> A[i];
    }
    cout << "YES" << endl;

    bool v[2000001] = {};
    vector< int > vs;
    while(vs.size() < N) {
      int val = rnd() % 1000000 + 1;
      bool flag = true;
      for(int j = 0; j < N; j++) flag &= !v[val + A[j]];
      if(flag) {
        vs.push_back(val);
        for(int j = 0; j < N; j++) v[val + A[j]] = true;
      }
    }

    for(int i = 0; i < vs.size(); i++) {
      cout << vs[i] << " ";
    }
    cout << endl;
  }
}