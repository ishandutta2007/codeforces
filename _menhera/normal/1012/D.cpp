#include<bits/stdc++.h>
using namespace std;
vector<pair<char, int> > as, bs;
int N;
vector<pair<int, int> > solve(int initmoveb, int initmovea)
{
  //printf("%d %d\n", initmoveb, initmovea);
  vector<pair<int, int> > ans;
  vector<pair<char, int> > na, nb;
  int bcnt = 0, acnt = 0;
  for(int i=0; i<initmoveb; ++i)
  {
    na.push_back(bs[i]);
    bcnt += bs[i].second;
  }
  for(int i=0; i<initmovea; ++i)
  {
    nb.push_back(as[i]);
    acnt += as[i].second;
  }
  for(int i=initmoveb; i<(int)bs.size(); ++i)
  {
    if (!nb.empty() && nb.back().first == bs[i].first)
      nb.back().second += bs[i].second;
    else
      nb.push_back(bs[i]);
  }
  for(int i=initmovea; i<(int)as.size(); ++i)
  {
    if (!na.empty() && na.back().first == as[i].first)
      na.back().second += as[i].second;
    else
      na.push_back(as[i]);
  }
  ans.emplace_back(bcnt, acnt);
  while(!nb.empty() && nb.back().first == 'b') nb.pop_back();
  while(!na.empty() && na.back().first == 'a') na.pop_back();

  while (na.size() != nb.size())
  {
    if(na.size() < nb.size())
    {
      char targ = (na.size()%2)?'a':'b';
      na.insert(na.begin(), make_pair(targ, 0));
    }
    else
    {
      char targ = (nb.size()%2)?'b':'a';
      nb.insert(nb.begin(), make_pair(targ, 0));
    }
  }
  
  
  /*
  for(auto x: nb) printf("%c %d\n", x.first, x.second);
  puts("");
  for(auto x: na) printf("%c %d\n", x.first, x.second);
  puts("");
  */
  int aswap = 0, bswap = 0;
  for(auto x: na) aswap += x.second;
  for(auto x: nb) bswap += x.second;
  bool swapped = false;
  for(int i=(int)na.size()-1; i>=0; --i)
  {
    ans.emplace_back(bswap, aswap);
    if (swapped)
    {
      swap(aswap, bswap);
      bswap -= nb[i].second;
      aswap -= na[i].second;
    }
    else
    {
      bswap -= nb[i].second;
      aswap -= na[i].second;
      swap(aswap, bswap);
    }
    swapped = !swapped;
  }
  return ans;
}
vector<pair<int, int> > solve(string s1, string s2)
{
  as.clear(); bs.clear();
  string s;
  s = s1+'b';
  char now = s[0]; int cnt = 1;
  for (int i=1; i<(int)s.size(); ++i)
  {
    if(now!=s[i])
    {
      bs.emplace_back(now, cnt);
      now = s[i]; cnt = 0;
    }
    ++cnt;
  }
  s = s2 + 'a';
  now = s[0]; cnt = 1;
  for (int i=1; i<(int)s.size(); ++i)
  {
    if(now!=s[i])
    {
      as.emplace_back(now, cnt);
      now = s[i]; cnt = 0;
    }
    ++cnt;
  }
  /*
  for(auto x: bs) printf("%c %d\n", x.first, x.second);
  puts("");
  for(auto x: as) printf("%c %d\n", x.first, x.second);
  puts("");
  */
  if((int)as.size() == 0 && (int)bs.size() == 0)
  {
    vector<pair<int, int> > ans;
    return ans;
  }
  
  int amove, bmove;
  
  bmove = (int)bs.size()%2; amove = (int)as.size()%2;
  if (!bmove && (int)bs.size() != 0) bmove += 2;
  if (!amove && (int)as.size() != 0) amove += 2;
  //printf("%d %d %d %d\n", amove, (int)as.size(), bmove, (int)bs.size());
  while(amove <= (int)as.size() && bmove <= (int)bs.size())
  {
    int bexp = amove + (int)bs.size() - bmove - 1;
    int aexp = bmove + (int)as.size() - amove - 1;
    if(abs(bexp-aexp) <= 2)
    {
      return solve(bmove, amove);
    }
    else if(aexp > bexp)
    {
      amove += 2;
    }
    else 
    {
      bmove += 2;
    }
  }
  assert(false);
}
int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  auto ans1 = solve(s1, s2);
  auto ans2 = solve(s2, s1);
  if(ans1.size() <= ans2.size())
  {
    printf("%d\n", (int)ans1.size());
    for(auto x: ans1) printf("%d %d\n", x.first, x.second);
  }
  else
  {
    printf("%d\n", (int)ans2.size());
    for(auto x: ans2) printf("%d %d\n", x.second, x.first);
  
  }
}