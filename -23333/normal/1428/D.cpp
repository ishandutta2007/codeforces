#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
int a[N];
queue<int> q,q2;
int main()
{
	int n;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	int cnt1=0,cnt2=0,cnt3=0,tt=0,tto=0;
	dep(i,n,1)
	{
	  if (a[i]==1) cnt1++;
	  if (a[i]==2) cnt2++;
	  if (a[i]==3)
	  { 
	    cnt3++;
	    if (cnt3==1&&cnt2==0) cnt1--,tto=1;
	  } 
	  if (cnt2>cnt1) tt=1;
    }
    if (tt)
    {
    	cout<<-1<<endl;
    	return 0;
    }
    cout<<cnt3*2+cnt2+cnt1+tto<<endl;
    dep(i,n,1)
    {
      if(a[i]==1)
      {
	    q2.push(i);
	    cout<<i<<" "<<i<<endl;
	  }
      if(a[i]==3)
      {
      	int x;
      	if (!q.empty())
		  { 
		    x=q.front(); q.pop();
		} else
		{
			x=q2.front();q2.pop();
		}
      	cout<<i<<" "<<i<<endl;
      	cout<<i<<" "<<x<<endl;
      	q.push(i);
      }
      if (a[i]==2)
      {
      	q.push(i); 
      	int x=q2.front();q2.pop();
      	cout<<x<<" "<<i<<endl;
      }
    }
	return 0; 
}