#include <iostream>
#include <list>
#include <vector>
#include <utility>

#define NMAX 100005
using namespace std;

struct muchie
{
    int a,b;
    bool viz;
};

int deg[NMAX];
vector<muchie*> graf[NMAX];

list<int> sol;
list<int>::iterator unde;

void expand(int nod)
{
    while(1)
    {
        while(graf[nod].size() && (*(graf[nod].end()-1))->viz==1)
            graf[nod].pop_back();

        if(graf[nod].size())
        {
            (*(graf[nod].end()-1))->viz=1;
            nod=(*(graf[nod].end()-1))->a+(*(graf[nod].end()-1))->b-nod;
            sol.insert(unde,nod);
        }
        else
            break;
    }
}

vector <int> real_sol;

void euler()
{
    sol.push_back(1);

    for(list<int>::iterator it=sol.begin();it!=sol.end();it++)
    {
        real_sol.push_back(*it);
        it++;
        unde=it;
        it--;
        expand(*it);
    }
}

vector <pair <int, int> > fin;
int main()
{
    ios_base :: sync_with_stdio(false);

    int n=0,m=0,i,a,b;

    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        cin>>a>>b;

        muchie *x;
        x=new muchie;

        x->a=a;
        x->b=b;
        x->viz=0;

        deg[a]++;
        deg[b]++;

        graf[a].push_back(x);
        graf[b].push_back(x);
    }

    int j;
    for (int i = 1; i <= n; i++)
        if (deg[i] & 1) {
            for (j = i + 1; j <= n; j++)
                if (deg[j] & 1) {
                    muchie *x;
                    x=new muchie;

                    x->a=i;
                    x->b=j;
                    x->viz=0;

                    graf[i].push_back(x);
                    graf[j].push_back(x);

                    i = j;
                    m ++;

                    break;
                }
        }

    if (m & 1) {
        muchie *x;
        x=new muchie;

        x->a=1;
        x->b=1;
        x->viz=0;

        graf[1].push_back(x);
        m ++;
    }

    euler();

    for (int i = 1; i < real_sol.size(); i++)
        if (i & 1)
            fin.push_back(make_pair(real_sol[i - 1], real_sol[i]));
        else
            fin.push_back(make_pair(real_sol[i], real_sol[i - 1]));

    cout << fin.size() << '\n';
    for (int i = 0; i < fin.size(); i++)
        cout << fin[i].first << ' ' << fin[i].second << '\n';

    return 0;
}