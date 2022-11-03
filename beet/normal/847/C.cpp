#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 X, Y;
  cin >> X >> Y;

  if(X * (X - 1) / 2 < Y) {
    cout << "Impossible" << endl;
    return (0);
  }

  int64 dep[500002] = {};
  int64 reach = 0;
  if(Y > 0) {
    int64 curr = 0;
    while(Y - curr >= 0) {
      dep[curr]++;
      Y -= curr;
      --X;
      reach = curr;
      ++curr;
    }
  }


  while(Y > 0 || X > 0) {
    dep[min(reach, Y)]++;
    Y -= min(reach, Y);
    --X;
  }

  deque< char > st;
  for(int i = 500000; i >= 0; i--) {
    if(dep[i] > 0) {
      st.emplace_front('(');
      st.emplace_back(')');
      --dep[i];
    }
    while(dep[i] > 0) {
      st.emplace_front(')');
      st.emplace_front('(');
      --dep[i];
    }
  }

  for(auto &s : st) cout << s;
  cout << endl;

}