#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 600000;
char s[1 + nmax];
int v[1 + nmax];

struct Sol{
  int smin;
  int result;
  int x, y;
  bool operator < (Sol const &a) const{
    return result < a.result;
  }
};

Sol query(int from, int to, int x, int y){
  int smin = 0, scount = 0;
  for(int i = from; i <= to; i++)
    if(v[i] < smin){
      smin = v[i];
      scount = 1;
    } else if(smin == v[i])
      scount++;
  return {smin, scount, x, y};
}

void update(int from, int to, int val){
  for(int i = from; i <= to; i++)
    v[i] += val;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> s[i];
  for(int i = 1;i <= n; i++)
    if(s[i] == '(')
      v[i] = v[i - 1] + 1;
    else
      v[i] = v[i - 1] - 1;
  if(0 != v[n]) {
    cout << 0 << '\n';
    cout << 1 << " " << 1 << '\n';
    return 0;
  }

  int smin = 0, scount = 0;
  for(int i = 1;i <= n; i++){
    if(v[i] < smin){
      smin = v[i];
      scount = 1;
    } else if(v[i] == smin)
      scount++;
  }
  Sol result = query(1, n, 1, 1);

  //+2
  int from = 0, to = 0;
  for(int i = 1;i <= n; i++)
    if(v[i] == smin) {
      to = i;
      if(from == 0)
        from = i;
    }

  if(s[from] == ')' && s[to + 1] == '(') {
    update(from, to, +2);
    Sol result2 = query(1, n, from, to + 1);
    if(result < result2)
      result = result2;
    update(from, to, -2);
  }

  from = 0;
  to = 0;
  for(int i = 1;i <= n; i++){
    if(v[i] == smin || v[i] == smin + 1) {
      to = i;
      if(from == 0)
        from = i;
    }
  }

  if(s[from] == ')' && s[to + 1] == '(') {
    update(from, to, +2);
    Sol result2 = query(1, n, from, to + 1);
    if(result < result2)
      result = result2;
    update(from, to, -2);
  }


  //-2 ()  ->  )(

  int last = 0;

  v[n + 1] = smin;
  for(int i = 1; i <= n + 1; i++){
    if(v[i] == smin){
      if(last + 1 == i)
        continue;

      if(s[last + 1] == '(' && s[i] == ')'){
        update(last + 1, i - 1, -2);

        Sol result2 = query(last + 1, i - 1, last + 1, i);
        if(result2.smin == smin)
          result2.result += scount;
        if(result < result2)
          result = result2;

        update(last + 1, i - 1, 2);
      }

      last = i;
    }
  }
  last = 0;
  for(int i = 1; i <= n + 1; i++){
    if(v[i] == smin || v[i] == smin + 1){
      if(last + 1 == i)
        continue;

      if(s[last + 1] == '(' && s[i] == ')'){
        update(last + 1, i - 1, -2);
        Sol result2 = query(last + 1, i - 1, last + 1, i);
        if(result2.smin == smin)
          result2.result += scount;
        if(result < result2)
          result = result2;

        update(last + 1, i - 1, 2);
      }
      last = i;

    }
  }

  cout << result.result << '\n';
  cout << result.x << " " << result.y << '\n';
  return 0;
}