#include<bits/stdc++.h>
using namespace std;

queue<int> zeros;
queue<int> ones;

int main()
{
string s;
cin>>s;
int n = s.length();
bool a[n] = {0};
for (int i = 0; i<n; i++) if (s[i]=='1') a[i] = 1;
int zerleft[n] = {0};
int oneleft[n] = {0};
int zerright[n] = {0};
int oneright[n] = {0};
if (!a[0]) zerleft[0]++;
else oneleft[0]++;
for (int i = 1; i<n; i++)
{
    zerleft[i] = zerleft[i-1];
    oneleft[i] = oneleft[i-1];
    if (a[i]) oneleft[i]++;
    else zerleft[i]++;
}


if (!a[n-1]) zerright[n-1]++;
else oneright[n-1]++;
for (int i = n-2; i>=0; i--)
{
    zerright[i] = zerright[i+1];
    oneright[i] = oneright[i+1];
    if (a[i]) oneright[i]++;
    else zerright[i]++;
}

for (int i = 0; i<n; i++) if (zerright[i]<oneright[i]) {cout<<-1; return 0;}
for (int i = 0; i<n; i++) if (zerleft[i]<oneleft[i]) {cout<<-1; return 0;}
int k = zerleft[n-1]-oneleft[n-1];
//cout<<zerleft[n-1]<<' '<<oneleft[n-1]<<endl;
if (k<=0) {cout<<-1; return 0;}
//cout<<"KEK"<<endl;
vector<vector<int>> subseq;
for (int i = 0; i<n; i++)
{
    vector<int> temp;
    subseq.push_back(temp);
}

for (int i = 0; i<k; i++) zeros.push(i);
for (int i = 0; i<n; i++)
{
    if (a[i]==0)
    {
        if (zeros.empty()) {cout<<-1; return 0;}
        int t = zeros.front();
        zeros.pop();
        subseq[t].push_back(i);
        ones.push(t);
    }
    else
    {
        if (ones.empty()) {cout<<-1; return 0;}
        int t = ones.front(); 
        ones.pop();
        subseq[t].push_back(i);
        zeros.push(t);
    }
}

cout<<k<<endl;
for (int i = 0; i<k; i++)
{
    cout<<subseq[i].size()<<' ';
    for (int j = 0; j<subseq[i].size(); j++) cout<<subseq[i][j]+1<<' ';
    cout<<endl;
}


}