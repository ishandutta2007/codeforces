#include <bits/stdc++.h>

using namespace std;

int n, k;

string s[110];
int a[105][13];

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; i++)
	  for (int j=0; j<12; j++)
	    a[i][j]=-1;
	for (int i=0; i<n; i++)
	{
	  cin >> s[i];
	  for (int j=1; j<11; j++)
	    if (s[i][j]=='.')
	    {
	        a[i][j]=0;
	    	if (s[i][j-1]=='S')
	    	  a[i][j]++;
	    	if (s[i][j+1]=='S')
	    	  a[i][j]++;
		}
	    if (s[i][0]=='.')
	      a[i][0]=0;
    	if (s[i][0]=='.' && s[i][1]=='S')
	      a[i][0]=1;
	    if (s[i][11]=='.' && s[i][10]=='S')
	      a[i][11]=1;
	    else if (s[i][11]=='.')
	      a[i][11]=0;
	}
	int p=0;
	while (k>0)
	{
		for (int i=0; i<n; i++)
		  for (int j=0; j<12; j++)
		    if (a[i][j]==p && k>0)
		      s[i][j]='x', k--;
		p++;
	}
/*	for (int i=0; i<n; i++)
	{
	  for (int j=0; j<12; j++)
	    cout << a[i][j] << " ";
	  cout << "\n";
	}*/
	int ans=0;
	for (int i=0; i<n; i++)
	  for (int j=0; j<12; j++)
	  {
	      if (s[i][j]=='S')
	      {
	          if (j>0 && (s[i][j-1]=='P' || (s[i][j-1]=='x' || s[i][j-1]=='S')))
	            ans++;
	          if (j<11 && (s[i][j+1]=='P' || (s[i][j+1]=='x' || s[i][j+1]=='S')))
	            ans++;
	      }
	  }
	cout << ans << "\n";
	for (int i=0; i<n; i++)
	  cout << s[i] << "\n";
}