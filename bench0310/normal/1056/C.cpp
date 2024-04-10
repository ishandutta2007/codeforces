#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int arr[2*n];
    for(int i=0;i<2*n;i++) cin >> arr[i];
    int a,b;
    set<pair<int,int> > unpaired;
    vector<pair<int,int> > paired;
    int idxp[2*n];
    for(int i=0;i<2*n;i++) idxp[i]=-1;
    int idxcur=0;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        a--; b--;
        if(arr[a]>arr[b])
        {
            paired.push_back(make_pair(arr[a],a));
            paired.push_back(make_pair(arr[b],b));
            idxp[a]=idxcur++;
            idxp[b]=idxcur++;
        }
        else
        {
            paired.push_back(make_pair(arr[b],b));
            paired.push_back(make_pair(arr[a],a));
            idxp[b]=idxcur++;
            idxp[a]=idxcur++;
        }
    }
    for(int i=0;i<2*n;i++)
    {
        if(idxp[i]==-1) unpaired.insert(make_pair(1000-arr[i],i));
    }
    int moves=2*n;
    int team;
    cin >> team;
    int x;
    if(team==1)
    {
        for(int i=0;i<(int)paired.size();i+=2)
        {
            cout << paired[i].second+1 << endl;
            cout.flush();
            moves--;
            cin >> x;
            moves--;
        }
        while(moves)
        {
            set<pair<int,int> >::iterator it=unpaired.begin();
            cout << (*it).second+1 << endl;
            cout.flush();
            unpaired.erase(it);
            moves--;
            cin >> x;
            x--;
            it=unpaired.find(make_pair(1000-arr[x],x));
            unpaired.erase(it);
            moves--;
        }
    }
    else
    {
        bool used[2*n];
        for(int i=0;i<2*n;i++) used[i]=0;
        cin >> x;
        x--;
        moves--;
        while(moves>0&&idxp[x]!=-1)
        {
            if(idxp[x]%2==0)
            {
                cout << paired[idxp[x]+1].second+1 << endl;
                cout.flush();
                used[x]=1;
                used[paired[idxp[x]+1].second]=1;
            }
            else
            {
                cout << paired[idxp[x]-1].second+1 << endl;
                cout.flush();
                used[x]=1;
                used[paired[idxp[x]-1].second]=1;
            }
            moves-=2;
            if(moves<=0) break;
            cin >> x;
            x--;
        }
        moves++;
        if(moves>0)
        {
            set<pair<int,int> >::iterator it=unpaired.find(make_pair(1000-arr[x],x));
            unpaired.erase(it);
            moves--;
        }
        if(moves)
        {
            for(int i=0;i<(int)paired.size();i+=2)
            {
                if(used[paired[i].second]) continue;
                cout << paired[i].second+1 << endl;
                cout.flush();
                moves--;
                cin >> x;
                moves--;
            }
        }
        while(moves)
        {
            set<pair<int,int> >::iterator it=unpaired.begin();
            cout << (*it).second+1 << endl;
            cout.flush();
            unpaired.erase(it);
            moves--;
            if(!moves) break;
            cin >> x;
            x--;
            it=unpaired.find(make_pair(1000-arr[x],x));
            unpaired.erase(it);
            moves--;
        }
    }
    return 0;
}