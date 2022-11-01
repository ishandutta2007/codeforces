#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    long long arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    string s;
    cin >> s;
    vector<int> v;
    v.push_back(0); //[)
    for(int i=1;i<n;i++) if(s[i]!=s[i-1]) v.push_back(i);
    v.push_back(n);
    long long dmg=0;
    for(int o=0;o<(int)v.size()-1;o++)
    {
        vector<int> temp;
        for(int i=v[o];i<v[o+1];i++) temp.push_back(arr[i]);
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        for(int i=0;i<min(k,(int)temp.size());i++) dmg+=temp[i];
    }
    cout << dmg << endl;
    return 0;
}