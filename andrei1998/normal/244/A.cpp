#include <iostream>
#include <vector>

using namespace std;

int viz[905];
vector<int> toti[35];

int main()
{
    int n,k,x;
    cin>>n>>k;

    for(int i=1;i<=k;i++){
        cin>>x;
        toti[i].push_back(x);
        viz[x]=1;
    }

    int j=1;
    for(int i=1;i<=k;i++){
        for(int p=1;p<n;p++){
            while(viz[j])
                j++;
            viz[j]=1;
            toti[i].push_back(j);
            j++;
        }
    }

    for(int i=1;i<=k;i++){
        cout<<toti[i].front();
        for(vector<int>::iterator it=toti[i].begin()+1;it!=toti[i].end();it++)
            cout<<' '<<(*it);
        cout<<endl;
    }

    return 0;
}