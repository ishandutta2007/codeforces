#include <bits/stdc++.h>

using namespace std;
vector<char> vec_erase(vector<char> vec, int pos, int siz){
    vector<char> out;
    int x = 0;
    for(int i=0;i<siz;i++){
        if(i==pos)x++;
        out.push_back(vec[i+x]);
    }
    return out;
}
bool ii(char c){
    return (c=='a' || c=='e' || c=='y' || c=='o' || c=='u' || c=='i');
}
void A(){
    int n;
    cin >> n;
    vector<char> ca(n);
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        ca[i]=c;
    }
    int pos = 1;
    while(pos <= n-1){
        if(ii(ca[pos-1]) && ii(ca[pos])){
            ca = vec_erase(ca, pos, n);
            pos=1;
            n--;
        }else{pos++;}
    }
    for(int i=0;i<n;i++){
        cout<<ca[i];
    }
}
void A231(){
    int n, c=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int j, k, l;
        cin >> j >> k >> l;
        if(j+k+l>=2)c++;
    }
    cout << c;
}
int main()
{
    A231();
}