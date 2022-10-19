#include<bits/stdc++.h>
using namespace std;
int S,mat[110];
char s[1010][1010],str[110];
void solveexpr(int,int,int,int,int&,int&);
void solveatom(int,int,int,int,int&,int&);
void solveordinary(int l,int r,int x,int y,int &n,int &m){//solve an atom without special characters
//	printf("ORDI:[%d,%d)\n",l,r);
	if(str[l]=='(')solveexpr(l+1,r-1,x,y,n,m);else solveexpr(l,r,x,y,n,m);
}
void solveplus(int l,int r,int x,int y,int &n,int &m){//solve a plus-type atom
	solveatom(l,r-1,x,y+3,n,m);
	for(int i=-1;i<m+2;i++)s[x+n+1][y+3+i]='-';
	s[x+n+1][y+0]='+';
	s[x+n+1][y+1]='<';
	s[x+n+1][y+3+m+2]='+';
	s[x+1][y+0]='+';
	s[x+1][y+1]='-';
	s[x+1][y+2]='>';
	s[x+1][y+3+m+0]='-';
	s[x+1][y+3+m+1]='>';
	s[x+1][y+3+m+2]='+';
	for(int i=2;i<n+1;i++)s[x+i][y+0]='|',s[x+i][y+3+m+2]='|';
	n+=2,m+=6;
}
void solvequestion(int l,int r,int x,int y,int &n,int &m){//solve a question-mark-type atom
//	printf("QUES:[%d,%d)\n",l,r);
	solveatom(l,r-1,x+3,y+3,n,m);
	for(int i=-2;i<m+1;i++)s[x+1][y+3+i]='-';
	s[x+1][y+0]='+';
	s[x+1][y+3+m+1]='>';
	s[x+1][y+3+m+2]='+';
	
	s[x+4][y+0]='+';
	s[x+4][y+1]='-';
	s[x+4][y+2]='>';
	s[x+4][y+3+m+0]='-';
	s[x+4][y+3+m+1]='>';
	s[x+4][y+3+m+2]='+';
	for(int i=2;i<4;i++)s[x+i][y+0]='|',s[x+i][y+3+m+2]='|';
	n+=3,m+=6;
}
void solveasterisk(int l,int r,int x,int y,int &n,int &m){//solve an asterisk-type atom
	solveatom(l,r-1,x+3,y+3,n,m);
	for(int i=-2;i<m+1;i++)s[x+1][y+3+i]='-';
	s[x+1][y+0]='+';
	s[x+1][y+3+m+1]='>';
	s[x+1][y+3+m+2]='+';
	
	s[x+4][y+0]='+';
	s[x+4][y+1]='-';
	s[x+4][y+2]='>';
	s[x+4][y+3+m+0]='-';
	s[x+4][y+3+m+1]='>';
	s[x+4][y+3+m+2]='+';
	for(int i=2;i<4;i++)s[x+i][y+0]='|',s[x+i][y+3+m+2]='|';
	
	for(int i=-1;i<m+2;i++)s[x+3+n+1][y+3+i]='-';
	s[x+3+n+1][y+0]='+';
	s[x+3+n+1][y+1]='<';
	s[x+3+n+1][y+3+m+2]='+';
	for(int i=2;i<n+1;i++)s[x+3+i][y+0]='|',s[x+3+i][y+3+m+2]='|';
	
	n+=5,m+=6;	
}
void solveatom(int l,int r,int x,int y,int &n,int &m){
	if(str[r-1]=='+'){solveplus(l,r,x,y,n,m);return;}
	if(str[r-1]=='?'){solvequestion(l,r,x,y,n,m);return;}
	if(str[r-1]=='*'){solveasterisk(l,r,x,y,n,m);return;}
	solveordinary(l,r,x,y,n,m);
}
void solvealpha(int l,int r,int x,int y,int &n,int &m){//solve an all-alpha term
//	printf("ALPHA:[%d,%d)\n",l,r); 
	n=3,m=r-l+4;
	for(int i=l;i<r;i++)s[x+1][y+2+i-l]=str[i];
	for(int i=l-1;i<r+1;i++)s[x][y+2+i-l]=s[x+2][y+2+i-l]='-';
	for(int i=0;i<3;i++)s[x+i][y+0]=s[x+i][y+2+r-l+1]='+';
}
bool isoperator(char x){return x=='+'||x=='?'||x=='*';}
void solveterm(int l,int r,int x,int y,int &n,int &m){
//	printf("TERM:[%d,%d)\n",l,r);
	bool allalpha=true;
	for(int i=l;i<r;i++)if(str[i]<'A'||str[i]>'Z'){allalpha=false;break;}
	if(allalpha){solvealpha(l,r,x,y,n,m);return;}
	n=m=0;
	for(int i=l;i<r;i++){
		if(str[i]!='('&&!isoperator(str[i]))continue;
		int L,R;
		if(str[i]=='(')L=i,R=mat[i]+1;else L=i-1,R=i;
		while(R<r&&isoperator(str[R]))R++;
		if(L!=l){
			solvealpha(l,L,x,y,n,m);
			s[x+1][y+m+0]='-',s[x+1][y+m+1]='>',m+=2;
		}
		int N,M;
		solveatom(L,R,x,y+m,N,M);
		n=max(n,N),m+=M;
		if(R!=r){
			s[x+1][y+m+0]='-',s[x+1][y+m+1]='>',m+=2;
			solveterm(R,r,x,y+m,N,M);
			n=max(n,N),m+=M;
		}
		return;
	}
}
void solveexpr(int l,int r,int x,int y,int &n,int &m){
//	printf("EXPR:[%d,%d)\n",l,r);
	bool findor=false;
	for(int i=l;i<r;i++){
		if(str[i]=='|'){findor=true;break;}
		if(str[i]=='(')i=mat[i];
	}
	if(!findor){solveterm(l,r,x,y,n,m);return;}
	int las=l;
	n=-1,m=0;
	vector<pair<int,int> >v;
	for(int i=l;i<=r;i++){
		if(str[i]=='(')i=mat[i];
		if(i!=r&&str[i]!='|')continue;
		int N,M;
		solveterm(las,i,x+n+1,y+3,N,M);
		v.emplace_back(n+2,M);
		n+=N+1;
		m=max(m,M);
		las=i+1;
	}
	for(int i=v[0].first;i<=v.back().first;i++)s[x+i][y]='|',s[x+i][y+3+m+2]='|';
	for(auto i:v){
		int N=i.first,M=i.second;
		s[x+N][y+0]='+',s[x+N][y+1]='-',s[x+N][y+2]='>',s[x+N][y+3+m+1]='>',s[x+N][y+3+m+2]='+';
		for(int i=M;i<m+1;i++)s[x+N][y+3+i]='-';
	}
	m+=6;
}
void solveinput(int l,int r,int x,int y,int &n,int &m){
	solveexpr(l,r,x,y+3,n,m);
	s[x+1][y+0]='S';
	s[x+1][y+1]='-';
	s[x+1][y+2]='>';
	s[x+1][y+3+m+0]='-';
	s[x+1][y+3+m+1]='>';
	s[x+1][y+3+m+2]='F';
	m+=6;
}
int n,m;
stack<int>stk; 
int main(){
	scanf("%s",str),S=strlen(str);
//	printf("%d\n",S);
	for(int i=0;i<S;i++){
		if(str[i]=='(')stk.push(i);
		if(str[i]==')')mat[stk.top()]=i,mat[i]=stk.top(),stk.pop();
	}
	for(int i=0;i<1000;i++)for(int j=0;j<1000;j++)s[i][j]=' ';
	solveinput(0,S,0,0,n,m);
	printf("%d %d\n",n,m);
	for(int i=0;i<n;i++,putchar('\n'))for(int j=0;j<m;j++)putchar(s[i][j]);
	return 0;
}
//(S(M(JQ|X))GRY)|(WP)
//(M(J|X))|(P)