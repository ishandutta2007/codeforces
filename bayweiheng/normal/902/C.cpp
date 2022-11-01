#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;



int main() {
    int h,cur;
    vi nodes;
    cin>>h;
    cin>>cur;
    nodes.push_back(cur);
    bool flag=0;
    int level;
    for(int i=0;i<h;i++) {
        cin>>cur;
        if(cur!=1 && nodes.back()!=1) {
            flag=1;
            level=nodes.size();
        }
        nodes.push_back(cur);
    }
    //cout<<"hello"<<endl;
    if(flag==0) cout<<"perfect"<<endl;
    else {
        cout<<"ambiguous"<<endl;
        int root=1,tmp;
        cout<<0;
        for(int i=1;i<nodes.size();i++) {
            int num=nodes[i];
            tmp=root+num;
            if(level==i) {
                printf(" %d",root-1);
                num--;
            }
            while(num--) {
                printf(" %d",root);
            }
            root=tmp;
        }
        cout<<endl;
        root=1;
        cout<<0;
        for(int i=1;i<nodes.size();i++) {
            int num=nodes[i];
            tmp=root+num;
            while(num--) {
                printf(" %d",root);
            }
            root=tmp;
        }
    }
}