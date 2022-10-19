#include <iostream>
#include <vector>
using namespace std;

int main() {
        int n, a, b, k;
        cin >> n >> a >> b >> k;
        bool c[200005];
        string p;
        cin >> p;
        int d = 0;
        int e = 0;
        int f = 0;
        for(int i=0; i<n; i++){
            c[i] = (p[i]=='1');
            if(!c[i]){
                d++;
                if(d==b){
                    d=0;
                    e++;
                    if(e==a){
                        f=i;
                    }
                }
            }else{
                d=0;
            }
        }
        //System.out.println(f);
        vector<int> g;
        d=0;
        bool h = true;
        for(int i=n-1; i>=0; i--){
            if(!c[i]){
                d++;
                if(d==b&&h){
                    if(i<=f){
                        h=false;
                    }
                    g.push_back(i);
                    d=0;
                }
            }else{
                d=0;
            }
        }
        cout << g.size() << endl;
        for(int i=g.size()-1; i>=0; i--){
             cout << g[i]+1;
            if(i>0){
                cout << " ";
            }
            else{
               	cout << endl;
            }
        }
        return 0;
    }