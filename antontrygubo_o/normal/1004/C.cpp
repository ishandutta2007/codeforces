#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
int n;
cin>>n;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
set<int> first;
vector<int> stops1;
for (int i = 0; i<n; i++)
{
   if (first.find(a[i])==first.end()) {first.insert(a[i]); stops1.push_back(i);}
}
set<int> second;
vector<int> temp;
for (int i = n-1; i>=0; i--)
{
   if (second.find(a[i])==second.end()) {second.insert(a[i]); temp.push_back(i);}
}
vector<int> stops2;
for (int i = temp.size()-1; i>=0; i--) stops2.push_back(temp[i]);

ll res = 0;


for (int i = 0; i<stops1.size(); i++)
{
    auto it = upper_bound(stops2.begin(), stops2.end(), stops1[i]);
    res+=(stops2.end()-it);
}
cout<<res;
}