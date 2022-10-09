#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int const nmax = 100000;
int v[5 + nmax];

void add(deque<int> &dq ,int pos , int coef){
  while(0 < dq.size() && 0 <= coef * (v[pos] - v[dq.back()]) )
    dq.pop_back();
  dq.push_back(pos);
}

void cleardq(deque<int> &dq , int pos){
  while(0 < dq.size() && dq.front() < pos)
    dq.pop_front();
}

int solmax = 0;
vector<int> sol;

int main()
{
  int n , k;
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  deque<int> dqmin , dqmax;
  int st = 1;

  for(int i = 1 ; i <= n ; i++){
    add(dqmax , i , 1);
    add(dqmin , i , -1);
    while(k < v[dqmax.front()] - v[dqmin.front()]){
      cleardq(dqmax , ++st);
      cleardq(dqmin , st);
    }

    if(solmax < i - st + 1){
      solmax = i - st + 1;
      sol.clear();
      sol.push_back(st);
    } else if(solmax == i - st + 1)
      sol.push_back(st);
  }
  cout << solmax << " " << sol.size() << '\n';
  for(int i = 0 ; i < sol.size() ; i++)
    cout << sol[i] << " " << sol[i] + solmax - 1 << '\n';

  return 0;
}