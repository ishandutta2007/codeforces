#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int lin[2505]; //Pozitia pe s
int col[2505];

int mat[55][55];
int c[55];
vector<pair<pair<int,int>,pair<int,int> > > ans;

int main()
{
    int n;
    cin>>n;

    int s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        s+=c[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=c[i];j++){
            cin>>mat[i][j];
            lin[mat[i][j]]=i;
            col[mat[i][j]]=j;
        }
    }
    //cout<<"da"<<endl;

    int k=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=c[i];j++){
            ans.push_back(make_pair(make_pair(i,j),make_pair(lin[k],col[k])));

            swap(lin[mat[i][j]],lin[k]);
            swap(col[mat[i][j]],col[k]);
            swap(mat[i][j],mat[lin[mat[i][j]]][col[mat[i][j]]]);
            k++;

            //cout<<i<<' '<<j<<endl;
        }

    int c=ans.size();
    for(vector<pair< pair<int,int>,pair<int,int> > >::iterator it=ans.begin();it!=ans.end();it++)
        if(it->first==it->second)
            c--;

    cout<<c<<'\n';
    for(vector<pair< pair<int,int>,pair<int,int> > >::iterator it=ans.begin();it!=ans.end();it++)
        if(it->first!=it->second)
            cout<<it->first.first<<' '<<it->first.second<<' '<<it->second.first<<' '<<it->second.second<<'\n';

    return 0;
}