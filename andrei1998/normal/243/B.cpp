#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int deg[100005];
int viz[100005];
vector<int> graf[100005];

vector<pair<int,int> > muchii;
vector<int> sol[2];
int u,v;
bool ok;

int main()
{
    int n,m,h,t;
    cin>>n>>m>>h>>t;

    int a,b;
    while(m--){
        cin>>a>>b;
        muchii.push_back(make_pair(b,a));
        deg[a]++,deg[b]++;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    vector<pair<int,int> >::iterator it;
    for(it=muchii.begin();it!=muchii.end();it++){
        a=it->first;
        b=it->second;

        if(deg[a]>=(h+1) && deg[b]>=(t+1)){
            //a -> h && b -> t
            if(deg[a]>=(h+t+1)){
                int i=1;
                for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end() && i<=t;it++)
                    if(*it!=a){
                        sol[1].push_back(*it);
                        viz[*it]=1;
                        i++;
                    }

                i=1;
                for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end() && i<=h;it++)
                    if(*it!=b && !viz[*it]){
                        sol[0].push_back(*it);
                        i++;
                    }

                u=a,v=b;
                ok=true;

                break;
            }
            else if(deg[b]>=(h+t+1)){
                int i=1;
                for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end() && i<=h;it++)
                    if(*it!=b){
                        sol[0].push_back(*it);
                        viz[*it]=1;
                        i++;
                    }

                i=1;
                for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end() && i<=t;it++)
                    if(*it!=a && !viz[*it]){
                        sol[1].push_back(*it);
                        i++;
                    }

                u=a,v=b;
                ok=true;

                break;
            }

            for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end();it++)
               viz[*it]=1;

            int i=1;
            for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end() && i<=t;it++)
                if(*it!=a && !viz[*it]){
                    sol[1].push_back(*it);
                    i++;
                }

            for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end() && i<=t;it++)
                if(*it!=a && viz[*it]){
                    sol[1].push_back(*it);
                    viz[*it]=2;
                    i++;
                }

            int j=1;
            for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end() && j<=h;it++)
                if(*it!=b && viz[*it]!=2){
                    sol[0].push_back(*it);
                    j++;
                }

            i--,j--;
            if(i==t && j==h){
                u=a,v=b;

                ok=true;
                break;
            }

            for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end();it++)
                viz[*it]=0;
            for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end();it++)
                viz[*it]=0;

            sol[0].clear();
            sol[1].clear();
        }

        //a -> t && b -> h
        swap(a,b);

        if(deg[a]>=(h+1) && deg[b]>=(t+1)){
            //a -> h && b -> t
            if(deg[a]>=(h+t+1)){
                int i=1;
                for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end() && i<=t;it++)
                    if(*it!=a){
                        sol[1].push_back(*it);
                        viz[*it]=1;
                        i++;
                    }

                i=1;
                for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end() && i<=h;it++)
                    if(*it!=b && !viz[*it]){
                        sol[0].push_back(*it);
                        i++;
                    }

                u=a,v=b;
                ok=true;

                break;
            }
            else if(deg[b]>=(h+t+1)){
                int i=1;
                for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end() && i<=h;it++)
                    if(*it!=b){
                        sol[0].push_back(*it);
                        viz[*it]=1;
                        i++;
                    }

                i=1;
                for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end() && i<=t;it++)
                    if(*it!=a && !viz[*it]){
                        sol[1].push_back(*it);
                        i++;
                    }

                u=a,v=b;
                ok=true;

                break;
            }


            for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end();it++)
               viz[*it]=1;

            int i=1;
            for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end() && i<=t;it++)
                if(*it!=a && !viz[*it]){
                    sol[1].push_back(*it);
                    i++;
                }

            for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end() && i<=t;it++)
                if(*it!=a && viz[*it]){
                    sol[1].push_back(*it);
                    viz[*it]=2;
                    i++;
                }

            int j=1;
            for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end() && j<=h;it++)
                if(*it!=b && viz[*it]!=2){
                    sol[0].push_back(*it);
                    j++;
                }

            i--,j--;
            if(i==t && j==h){
                u=a,v=b;

                ok=true;
                break;
            }

            for(vector<int>::iterator it=graf[a].begin();it!=graf[a].end();it++)
                viz[*it]=0;
            for(vector<int>::iterator it=graf[b].begin();it!=graf[b].end();it++)
                viz[*it]=0;

            sol[0].clear();
            sol[1].clear();
        }
    }

    if(!ok){
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    cout<<u<<' '<<v<<endl;

    cout<<sol[0].front();
    for(vector<int>::iterator it=sol[0].begin()+1;it!=sol[0].end();it++)
        cout<<' '<<*it;
    cout<<endl;

    cout<<sol[1].front();
    for(vector<int>::iterator it=sol[1].begin()+1;it!=sol[1].end();it++)
        cout<<' '<<*it;

    return 0;
}