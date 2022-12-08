#include <bits/stdc++.h>

using namespace std;

const int limite=10000;

void minimiza(char &a,char b)
{
  a=min(a,b);
}

int m;
int n;
string s;
int puede[limite];
string sol;

int main()
{
  ios::sync_with_stdio(false);
  cin>>s;
  n=int(s.size());
  int m=0;
  while ((1<<(m+1))<=n) m++;
  puede[0]=1;
  int lensol=n-((1<<m)-1);
  for (int paso=0;paso<lensol;paso++) {
    char mini='z';
    for (int c=0;c<1<<m;c++) {
      if (puede[c]) {
	for (int b=0;b<m;b++) {
	  int nextc=c|(1<<b);
	  if (paso+nextc<n)
	    puede[nextc]=1;
	}
	int pos=paso+c;
	minimiza(mini,s[pos]);
      }
    }
    sol+=string(1,mini);
    for (int c=0;c<1<<m;c++) {
      if (puede[c]) {
	int pos=paso+c;
	if (s[pos]!=mini) puede[c]=0;
      }
    }
  }
  cout<<sol<<endl;
}