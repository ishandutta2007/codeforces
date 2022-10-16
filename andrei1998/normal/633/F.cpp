#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>

#define NMAX 100005
#define lint long long int
using namespace std;

vector<int> graf[NMAX];
vector<int> graf2[NMAX];

lint v[NMAX];

lint din[NMAX]; //Lant in jos din i
lint best[NMAX]; //Lant stramb din subarborele lui i
lint sus[NMAX]; //Lant in sus din i
lint fara[NMAX]; //Lant in afara subarborelui lui i

bool cmp(const lint &a,const lint &b)
{
    return (din[a]>din[b]);
}

bool cmp2(const lint &a,const lint &b)
{
    return (best[a]>best[b]);
}

lint rasp;

void dfs(int nod,int father)
{
    vector<int>::iterator aux=graf[nod].end();
    for(vector<int>::iterator it=graf[nod].begin();it!=graf[nod].end();it++)
        if((*it)!=father)
            dfs(*it,nod);
        else
            aux=it;

    if(aux!=graf[nod].end())
        graf[nod].erase(aux);

    graf2[nod]=graf[nod];
    //sort(graf[nod].begin(),graf[nod].end(),cmp);
    if(graf[nod].size()>=1)
        nth_element(graf[nod].begin(),graf[nod].begin(),graf[nod].end(),cmp);
    if(graf[nod].size()>=2)
        nth_element(graf[nod].begin()+1,graf[nod].begin()+1,graf[nod].end(),cmp);
    if(graf[nod].size()>=3)
        nth_element(graf[nod].begin()+2,graf[nod].begin()+2,graf[nod].end(),cmp);

    if(!graf[nod].empty())
        din[nod]=v[nod]+din[*(graf[nod].begin())];
    else
        din[nod]=v[nod];

    if(graf[nod].size()<=1)
        best[nod]=din[nod];
    else
        best[nod]=v[nod]+din[*(graf[nod].begin())]+din[*(graf[nod].begin()+1)];

    for(vector<int>::iterator it=graf[nod].begin();it!=graf[nod].end();it++)
        if(best[*it]>best[nod])
            best[nod]=best[*it];
    //sort(graf2[nod].begin(),graf2[nod].end(),cmp2);
    if(graf2[nod].size()>=1)
        nth_element(graf2[nod].begin(),graf2[nod].begin(),graf2[nod].end(),cmp2);
    if(graf2[nod].size()>=2)
        nth_element(graf2[nod].begin()+1,graf2[nod].begin()+1,graf2[nod].end(),cmp2);
    if(graf2[nod].size()>=3)
        nth_element(graf2[nod].begin()+2,graf2[nod].begin()+2,graf2[nod].end(),cmp2);

}

void dfs2(int nod,int father)
{
    if(!father)
        sus[nod]=v[nod],fara[nod]=0;
    else{
        //cout<<"se calculeaza tatal lui "<<nod<<endl;
        if(graf[father].size()==1)
            sus[nod]=v[nod]+sus[father];
        else{
            if(nod!=(*graf[father].begin())){
                sus[nod]=v[nod]+v[father]+din[(*graf[father].begin())];
                //cout<<"caz 1"<<endl;
            }
            else{
                sus[nod]=v[nod]+v[father]+din[(*(graf[father].begin()+1))];
                //cout<<"caz 2"<<endl;
            }
            sus[nod]=max(sus[nod],v[nod]+sus[father]);
            //cout<<"varianta "<<v[nod]+sus[father]<<endl;
        }

        //Aici calculam fara[nod]
        //Intai incercam cu un best

        //cout<<"incercam lant direct pentru "<<nod<<endl;
        if(graf2[father].size()>1){
            if(nod!=(*graf2[father].begin())){
                fara[nod]=best[(*graf2[father].begin())];
              //  cout<<"se ia bset la nod "<<(*graf2[father].begin())<<endl;
            }
            else{
                fara[nod]=best[(*(graf2[father].begin()+1))];

            //    cout<<"se ia bset la nod "<<(*(graf2[father].begin()+1))<<endl;
            }
        }

        //cout<<"acum avem "<<nod<<' '<<fara[nod]<<endl;
        fara[nod]=max(fara[nod],fara[father]);
        //cout<<"acum avem "<<nod<<' '<<fara[nod]<<endl;


        //Mai raman dar variantele jos-jos si sus-jos
        //Sus-jos

        lint aux=0;
        if(graf[father].size()>1){
            if(nod!=(*graf[father].begin()))
                aux=din[(*graf[father].begin())];
            else
                aux=din[(*(graf[father].begin()+1))];
        }

        aux+=sus[father];
        fara[nod]=max(fara[nod],aux);

        //Jos-jos
        lint alese=0;
        aux=v[father];

        for(vector<int>::iterator it=graf[father].begin();it!=graf[father].end() && alese<2;it++)
            if(*it!=nod){
                //cout<<"se pune "<<*it<<endl;
                alese++;
                aux+=din[*it];
            }

        fara[nod]=max(fara[nod],aux);
    }

    rasp=max(rasp,best[nod]+fara[nod]);
    for(vector<int>::iterator it=graf[nod].begin();it!=graf[nod].end();it++)
        dfs2(*it,nod);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n=0,a,b;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>v[i];

        din[i]=sus[i]=best[i]=fara[i]=0;
    }

    for(int i=1;i<n;i++){
        cin>>a>>b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    rasp=0;
    dfs(1,0);
    dfs2(1,0);

    cout<<rasp<<'\n';

    return 0;
}