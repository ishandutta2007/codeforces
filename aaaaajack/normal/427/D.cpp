#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
void c_sort(vector<int>& s,vector<int>& value,int ub){
	vector<int> count(ub+1,0),new_s(s.size());
	int i;
	for(i=0;i<s.size();i++) count[value[s[i]]]++;
	for(i=0;i<ub;i++) count[i+1]+=count[i];
	for(i=s.size()-1;i>=0;i--){
		new_s[--count[value[s[i]]]]=s[i];
	}
	s=new_s;
}
vector<int> suffix_array(const string& s){
	vector<int> value(s.size()),x(s.size()),svalue(s.size()),temp(s.size());
	int i,ub=s.size()>128?s.size():128;
	for(i=0;i<s.size();i++) x[i]=i,value[i]=s[i];
	int r;
	for(r=1;r<s.size();r<<=1){
		for(i=0;i<s.size();i++){
			if(i+r<s.size()) svalue[i]=value[i+r];
			else svalue[i]=0;
		}
		c_sort(x,svalue,ub);
		c_sort(x,value,ub);
		temp[x[0]]=1;
		for(i=1;i<s.size();i++){
			if(value[x[i]]==value[x[i-1]]&&svalue[x[i]]==svalue[x[i-1]]) temp[x[i]]=temp[x[i-1]];
			else temp[x[i]]=temp[x[i-1]]+1;
		}
		if(temp[x[s.size()-1]]==s.size()) break;
		value=temp;
	}
	return x;
}
vector<int> longest_common_prefix(vector<int>& sar,const string& s){
    vector<int> len(s.size()),od(s.size());
    int pre,l,i;
    for(i=0;i<sar.size();i++) od[sar[i]]=i;
    for(i=0;i<s.size();i++){
        if(i) l=len[od[i-1]]?len[od[i-1]]-1:0;
        else l=0;
        l=0;
        if(od[i]==0){
            l=0;
        }
        else{
            pre=sar[od[i]-1];
            while(pre+l<s.size()&&i+l<s.size()&&s[pre+l]==s[i+l]) l++;
        }
        len[od[i]]=l;
    }
    return len;
}
int main(){
	string s1,s2,mix;
    cin>>s1>>s2;
    mix=s1+'$'+s2;
    int ans=mix.size(),i,temp;
    vector<int> sar(suffix_array(mix));
    vector<int> lcp(longest_common_prefix(sar,mix));
    //for(i=0;i<mix.size();i++){
      //  printf("%c %2d\n",mix[sar[i]],lcp[i]);
    //}
    lcp.push_back(0);
    for(i=1;i<sar.size();i++){
        if( (sar[i]<s1.size()&&sar[i-1]>s1.size()) || (sar[i]>s1.size()&&sar[i-1]<s1.size()) ){
            if(lcp[i]>lcp[i-1]&&lcp[i]>lcp[i+1]){
                temp=lcp[i-1]>lcp[i+1]?lcp[i-1]+1:lcp[i+1]+1;
                if(temp<ans) ans=temp;
            }
        }
    }
    if(ans==mix.size()) printf("-1\n");
    else printf("%d\n",ans);
	return 0;
}