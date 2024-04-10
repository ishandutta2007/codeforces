#include <iostream>
#include <math.h>
using namespace std;


int main() {
    
    

    int a;
    cin >> a;
    int b[100000];
    int l=-1;
    int m=-1;
    int n=-1;
    for(int i=1; i<=a; i++){
        cin >> b[i];
    }
    for(int i=1; i<=a; i++){
        if(b[i]==i){
            l=i;
        }
    }
    for(int i=1; i<=a; i++){
        if(b[b[i]]==i&&b[i]!=i){
            m=i;
            n=b[i];
        }
    }
    if(l!=-1){
        cout << "YES" << endl;
        for(int i=1; i<=a; i++){
            if(l!=i){
                cout << l << " " << i << endl;
            }
        }
    }
    else if(m!=-1){
        bool possible=true;
        int d[100000];
        for(int i=1; i<=a; i++){
            d[i]=0;
            if(i==m){
                d[i]=1;
            }
            if(i==n){
                d[i]=2;
            }
        }
        for(int i=1; i<=a; i++){
            if(d[i]==0){
                int j=i;
                d[j]=1;
                while(d[b[j]]==0){
                    d[b[j]]=3-d[j];
                    j=b[j];
                }
                if(d[j]+d[b[j]]!=3){
                    possible=false;
                }
                
            }
        }
        if(!possible){
            cout << "NO";
        }
        else{
            cout << "YES" << endl;
            cout << m << " " << n << endl;
            for(int i=1; i<=a; i++){
                if(i!=n&&i!=m){
                    if(d[i]==1){
                        cout << m << " " << i << endl;
                    }
                    if(d[i]==2){
                        cout << i << " " << n << endl;
                    }
                }
            }
        }
    }
    else {
        cout << "NO";
    }
}