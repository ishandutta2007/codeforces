#include <iostream>

using namespace std;

int const nmax = 200000;
int sum[1 + nmax], last[1 + nmax];
int sum2[1 + nmax], last2[1 + nmax];

pair<int, int> extract(int from, int to){
  return {sum[to] - sum[from - 1], to - max(last[to], from - 1)};
}

pair<int, int> extract2(int from, int to){
  return {sum2[to] - sum2[from - 1], to - max(last2[to], from - 1)};
}

bool canget(pair<int,int> f, pair<int,int> f2){
  if(f.first < 0 || f.second < 0 || f2.first < 0 || f2.second < 0)
    return 0;
  if(f.first == 0 && 0 < f2.first){
    if(f2.second < f.second){
      f.second = f2.second;
      f.first += 2;
      return canget(f, f2);
    } else
      return 0;
  }

  if(f.second == f2.second)
    return ((f.first <= f2.first) && (f2.first % 2 == f.first % 2));
  else if(f.second < f2.second){
    return 0;
  } else if(f.second % 3 == f2.second % 3){
    f.second -= (f.second - f2.second);
    return canget(f, f2);
  } else {
    f.second = f2.second;
    f.first += 2;
    return canget(f, f2);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s, t;
  cin >> s >> t;
  s = "#" + s;
  t = "#" + t;
  for(int i = 1;i < s.size(); i++){
    if(s[i] != 'A'){
      sum[i] = 1;
      last[i] = i;
    }
    sum[i] += sum[i - 1];
    last[i] = max(last[i - 1], last[i]);
  }
  for(int i = 1; i < t.size(); i++){
    if(t[i] != 'A'){
      sum2[i] = 1;
      last2[i] = i;
    }
    sum2[i] += sum2[i - 1];
    last2[i] = max(last2[i - 1], last2[i]);
  }
  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << canget(extract(a, b), extract2(c, d));
  }
  return 0;
}