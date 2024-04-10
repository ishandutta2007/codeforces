#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string siruri[105];
int ans[30];
vector<int> graf[30];
int grad[30];

void divide (int lit, int sus, int jos) {
    if(sus==jos || lit==100)
        return;

    int l1,l2;

    int incep=sus;
    for(int i=sus+1;i<=jos;i++) {
        if(lit<siruri[i-1].size())
            l1=siruri[i-1][lit]-'a'+1;
        else
            l1=0;

        if(lit<siruri[i].size())
            l2=siruri[i][lit]-'a'+1;
        else
            l2=0;

        if(l1!=l2) {
            graf[l1].push_back(l2);

            grad[l2]++;
            divide(lit+1,incep,i-1);
            incep=i;
        }
    }

    divide(lit+1,incep,jos);
}

queue<int> coada;

inline bool bfs () {
    for(int i=0;i<=26;i++)
        if(!grad[i])
            coada.push(i);

    int y;
    vector<int>::iterator it;

    int poz=0;
    while(!coada.empty()) {
        y=coada.front();
        coada.pop();
        ans[poz++]=y;

        for(it=graf[y].begin();it!=graf[y].end();it++) {
            grad[*it]--;
            if(!grad[*it])
                coada.push(*it);
        }
    }

    if(ans[0])
        return false;
    return (poz==27);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>siruri[i];
    divide(0,1,n);

    for(int i=1;i<=26;i++) {
        graf[0].push_back(i);
        grad[i]++;
    }

    if(bfs()) {
        for(int i=1;i<=26;i++)
            cout<<(char)(ans[i]-1+'a');
        cout<<'\n';
    }
    else
        cout<<"Impossible\n";

    return 0;
}