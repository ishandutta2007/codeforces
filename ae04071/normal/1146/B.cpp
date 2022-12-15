#include <bits/stdc++.h>
using namespace std;
using pci = pair<char,int>;

char str[100100];
int n;

int main() {
    int lst=-1;
    scanf("%s",str);
    n=strlen(str);
    vector<pci> arr;
    for(int i=0;i<n;i++) {
        if(str[i]=='a') lst=i;
        else arr.push_back({str[i],i});
    }
    if(arr.size()==0) {
        printf("%s\n",str);
        return 0;
    }

    int m=(int)arr.size();
    if(m%2==1 || lst > arr[m/2].second) {
        puts(":(");
        return 0;
    }
    for(int i=0;i<m/2;i++) if(arr[i].first != arr[i+m/2].first) {
        puts(":(");
        return 0;
    }
    for(int i=0;i<arr[m/2].second;i++) printf("%c",str[i]);
    
    return 0;
}