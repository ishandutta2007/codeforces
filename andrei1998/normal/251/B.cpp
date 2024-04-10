#include <iostream>
#include <vector>

using namespace std;

vector<int> q,inv_q,s;
vector<int> curent;

inline void apply (vector<int> a, vector<int> &b) {
    vector<int> nou(b.size(),0);
    for(int i=0;i<b.size();i++)
        nou[i]=b[a[i]];

    b=nou;
}

int main()
{
    int n=1,k=1;
    cin>>n>>k;

    int x;
    for(int i=1;i<=n;i++) {
        cin>>x;x--;
        q.push_back(x);
    }

    for(int i=1;i<=n;i++) {
        cin>>x;x--;
        s.push_back(x);
    }

    inv_q.resize(n,0);
    for(int i=0;i<n;i++)
        inv_q[q[i]]=i;

    for(int i=0;i<n;i++)
        curent.push_back(i);

    if(curent==s) {
        cout<<"NO\n";
        return 0;
    }

    int unde1=-1;
    int at_least1=0;
    for(int i=1;i<=k;i++) {
        apply(q,curent);

        if(curent==s) {
            if(i%2==k%2) {
                unde1=i;
                break;
            }
            else
                break;
        }

        if(i==1)
            at_least1=1;
    }

    curent.clear();
    for(int i=0;i<n;i++)
        curent.push_back(i);

    int unde2=-1;
    int at_least2=0;
    for(int i=1;i<=k;i++) {
        apply(inv_q,curent);

        if(curent==s) {
            if(i%2==k%2) {
                unde2=i;
                break;
            }
            else
                break;
        }

        if(i==1)
            at_least2=1;
    }

    if(k==1) {
        if(unde1==1 || unde2==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        return 0;
    }

    if(unde1!=-1) {
        if(unde1==1) {
            if(at_least1 || at_least2) {
                cout<<"YES\n";
                return 0;
            }
        }
        else {
            cout<<"YES\n";
            return 0;
        }
    }

    if(unde2!=-1) {
        if(unde2==1) {
            if(at_least1 || at_least2) {
                cout<<"YES\n";
                return 0;
            }
        }
        else {
            cout<<"YES\n";
            return 0;
        }
    }

    cout<<"NO\n";
    return 0;
}