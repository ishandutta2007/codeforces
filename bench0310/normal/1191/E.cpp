#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> one,two;
int onel,oner,twol,twor;

void smallest(vector<int> &v,int l,int r,int &a)
{
    if(v.empty()) return;
    if(v[0]<l) a=v[0];
    else
    {
        int ll=-1,rr=v.size();
        while(ll<rr-1)
        {
            int m=(ll+rr)/2;
            if(v[m]<=r) ll=m;
            else rr=m;
        }
        if(rr!=(int)v.size()) a=v[rr];
    }
}

void biggest(vector<int> &v,int l,int r,int &a)
{
    if(v.empty()) return;
    if(v.back()>r) a=v.back();
    else
    {
        int ll=-1,rr=v.size();
        while(ll<rr-1)
        {
            int m=(ll+rr)/2;
            if(v[m]<l) ll=m;
            else rr=m;
        }
        if(ll!=-1) a=v[ll];
    }
}

void paint(int l,int r,int col)
{
    onel=twol=-1;
    oner=twor=n+1;
    if(col==1)
    {
        onel=l;
        oner=r;
        if(!one.empty())
        {
            onel=min(onel,one[0]);
            oner=max(oner,one.back());
        }
        smallest(two,l,r,twol);
        biggest(two,l,r,twor);
    }
    else
    {
        twol=l;
        twor=r;
        if(!two.empty())
        {
            twol=min(twol,two[0]);
            twor=max(twor,two.back());
        }
        smallest(one,l,r,onel);
        biggest(one,l,r,oner);
    }
}

int main()
{
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i=0;i<n;i++)
    {
        if(s[i]=='0') one.push_back(i);
        else two.push_back(i);
    }
    bool win=0,lose=0,draw=0;
    for(int i=0;i+k-1<n;i++)
    {
        //cout << "in " << i << " " << i+k-1 << endl;
        //cout << "painting 1" << endl;
        paint(i,i+k-1,1);
        if(twol==-1) win=1;
        else if(min(oner-onel+1,twor-twol+1)<=k) lose=1;
        else draw=1;
        //cout << "1: " << onel << " " << oner << endl;
        //cout << "2: " << twol << " " << twor << endl;
        //cout << win << lose << draw << endl;
        //cout << "painting 2" << endl;
        paint(i,i+k-1,2);
        if(onel==-1) win=1;
        else if(min(oner-onel+1,twor-twol+1)<=k) lose=1;
        else draw=1;
        //cout << "1: " << onel << " " << oner << endl;
        //cout << "2: " << twol << " " << twor << endl;
        //cout << win << lose << draw << endl << endl;
    }
    if(win) cout << "tokitsukaze" << endl;
    else if(draw) cout << "once again" << endl;
    else cout << "quailty" << endl;
	return 0;
}