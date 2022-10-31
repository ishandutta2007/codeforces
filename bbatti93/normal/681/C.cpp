#include<bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> sor;

vector<string> valasz;
vector<int> valasz2;
int main () {
    cin>>n;
    for (int i=1; i<=n; i++) {
        string s;
        cin>>s;
        if (s=="removeMin") {
            if (sor.empty()) {
                valasz.push_back("insert");
                valasz2.push_back(1);
            }
            else {
                sor.pop();
            }
            valasz.push_back("removeMin");
            valasz2.push_back(0);
        }
        else {
            int a;

            if (s=="insert") {
                cin>>a;
                a=-a;
                sor.push(a);
                valasz.push_back("insert");
                valasz2.push_back(a);
            }
            if (s=="getMin") {
                cin>>a;
                a=-a;
                while (!sor.empty() && sor.top()>a) {
                    valasz.push_back("removeMin");
                    valasz2.push_back(0);
                    sor.pop();
                }
                if (sor.empty() || sor.top()!=a) {
                    sor.push(a);
                    valasz.push_back("insert");
                    valasz2.push_back(a);
                }
                valasz.push_back("getMin");
                valasz2.push_back(a);
            }
        }
    }
    cout<<valasz.size()<<endl;
    for (int i=0; i<valasz.size(); i++) {
        printf(valasz[i].c_str());
        if (valasz[i]=="getMin" || valasz[i]=="insert") printf(" %d", -valasz2[i]);
        printf("\n");
    }


}