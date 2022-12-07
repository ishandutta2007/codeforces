#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 50005
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<ll, int> Pli;
const ll infll = (ll)1e11;

char s[maxn];
int n;
ll val[maxn], ans;
priority_queue <Pli, vector<Pli>, greater<Pli> > que;// val, id.
bool open[maxn];
int main(){
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for(int i = 1;i <= n;i++){
    if(s[i] == '(') val[i] = -infll, ans += infll;
    else if(s[i] == ')') val[i] = infll;
    else{
      int a,b;
      scanf("%d%d",&a,&b);
      val[i] = a - b;
      ans += b;
    }
  }
  for(int i = 2;i <= n;i += 2){
    que.push(mp(val[i - 1],i - 1));
    Pli p = que.top();
    ans += p.first;
    open[p.second] = true;
    que.pop();
    que.push(mp(val[i],i));
  }
  if(ans >= infll) puts("-1");
  else{
    printf("%lld\n", ans >= infll ? -1 : ans);
    for(int i = 1;i <= n;i++) printf("%c", open[i] ? '(' : ')');
    printf("\n");
  }
  return 0;
}