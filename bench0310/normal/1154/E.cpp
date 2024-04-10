#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<pair<int,int> > v; //skill,index
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    vector<int> id;
    for(int i=0;i<n;i++) id.push_back(v[i].second);
    vector<int> team(n,0);
    int l[n],r[n];
    for(int i=1;i<n;i++) l[i]=i-1;
    for(int i=0;i<n-1;i++) r[i]=i+1;
    l[0]=-1; r[n-1]=-1;
    int idx=0;
    int trainer=1;
    while(idx<n)
    {
        int now=id[idx];
        if(team[now])
        {
            idx++;
            continue;
        }
        /*cout << "current team status: ";
        for(int i=0;i<n;i++) cout << team[i];
        cout << endl;
        cout << "left: ";
        for(int i=0;i<n;i++) cout << l[i] << " ";
        cout << endl;
        cout << "right: ";
        for(int i=0;i<n;i++) cout << r[i] << " ";
        cout << endl;
        cout << "in with idx=" << idx << endl;
        cout << "current id: " << now << endl;
        cout << endl;*/
        team[now]=trainer;
        int right=now;
        for(int i=0;i<k;i++)
        {
            right=r[right];
            if(right==-1) break;
            team[right]=trainer;
        }
        if(right!=-1) right=r[right];
        int left=now;
        for(int i=0;i<k;i++)
        {
            left=l[left];
            if(left==-1) break;
            team[left]=trainer;
        }
        if(left!=-1) left=l[left];
        if(left!=-1) r[left]=right;
        if(right!=-1) l[right]=left;
        trainer=(3-trainer);
    }
    for(int i=0;i<n;i++) cout << team[i];
    cout << endl;
    return 0;
}