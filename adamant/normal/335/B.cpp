#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <limits>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <ios>
 
using namespace std;
 
#define tr(c, it)  for(typeof(c.begin()) it=c.begin();  it != c.end(); it++)
#define rall(c) c.rbegin(),c.rend()
#define F(i,x) for(int i=0;i<x;i++)
#define all(c) c.begin(),c.end()
#define p(i,j) pair<i,j>
#define ld long double
#define v(i) vector<i>
#define d(i) deque<i>
#define int long long
#define mp make_pair
#define pb push_back


  main()
 {   
  string s;
  cin>>s;
  if(s.size()>3000)
  s=s.substr(0,3000);
  int n=s.size();
  int**L=new int*[n];
  int**a=new int*[n];
  F(i,n)
  {L[i]=new int[n];a[i]=new int[n];}
  F(i,n)
L[i][i]=1;
F(i,n-1)
L[i][i+1]=s[i]==s[i+1]?2:1;
for(int i=2;i<n;i++)
for(int j=0;j<n-i;j++)
L[j][i+j]=s[j]!=s[i+j]?max(L[j][i+j-1],L[j+1][i+j]):L[j+1][i+j-1]+2;
  string palindrome(L[0][n-1],'a');
  string::iterator palLeft=palindrome.begin(),palRight=palindrome.end(),left=s.begin(),right=s.end();
  right--;
  palRight--;
  while(left<=right)
  {
        if (left == right && L[left-s.begin()][right-s.begin()] == 1)
        {*palLeft = *left;palLeft++,left++;}
        else if(*left==*right)
        {*palLeft = *left;palLeft++,left++;
        *palRight = *right;palRight--,right--;}
        else if(L[left - s.begin() + 1][right-s.begin()] > L[left-s.begin()][right - s.begin() - 1])
        left++;
        else
        right--;
  }
if(palindrome.size()>100)
{
string b=palindrome.substr(0,50);
palindrome=b;
reverse(all(b));
palindrome+=b;
}
  cout<<palindrome<<endl;

 }