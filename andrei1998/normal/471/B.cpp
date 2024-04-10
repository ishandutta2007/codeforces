#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> toate[2005];
vector<vector<int> > sols;
vector<int> sol;
bool gata;

void backtr(int poz){
    if(poz==2001){
        sols.push_back(sol);
        if(sols.size()==3)
            gata=true;

        return;
    }

    do{
        for(int i=0;i<toate[poz].size();i++)
            sol.push_back(toate[poz][i]);

        backtr(poz+1);
        if(gata)
            return;

        for(int i=0;i<toate[poz].size();i++)
            sol.pop_back();
    }while(next_permutation(toate[poz].begin(),toate[poz].end()));
}

int main()
{
    int n=0;

    cin>>n;

    int x=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        toate[x].push_back(i);
    }

    backtr(1);

    if(!gata){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";

    cout<<sols[0][0];
    for(int i=1;i<sols[0].size();i++)
        cout<<' '<<sols[0][i];
    cout<<'\n';

    cout<<sols[1][0];
    for(int i=1;i<sols[1].size();i++)
        cout<<' '<<sols[1][i];
    cout<<'\n';

    cout<<sols[2][0];
    for(int i=1;i<sols[2].size();i++)
        cout<<' '<<sols[2][i];
    cout<<'\n';

    return 0;
}