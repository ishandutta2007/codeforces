	#include<cstdio>


	#include<cstring>

		#include<cmath>


		#include<cstdlib>


		#include<iostream>


		#include<algorithm>

		#include<string>


	#include<vector>



	#include<queue>

	#include<set>


			#include<map>

		using namespace std;


	typedef double db;


	typedef long long ll;


		typedef pair<int  , int> pi;

			typedef unsigned int uint;

			typedef unsigned long long ull;

	//#define maxn



		//#define maxe


			//#define mod 1e9+7


#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((x).size())
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define grp(i,x) for (int i=edge.lnk[x];i;i=edge.nxt[i])
#define vec(i,x) for (int i=0;i<sz(x);i++)



			int rint ( )


	{


		int x=0 ,  f=1;char ch=getchar (  ) ;

	while   ( (   ch<'0'||ch>'9'  )   &&  (  ch !=  '-'  )  )  ch=getchar ( )  ;


			if  (  ch  ==  '-' )  f=-1  , ch=getchar (  )  ;


		while   ( ch >=   '0'&&ch  <= '9'  )  x=x*10+ch-'0'  , ch=getchar  ( ) ;


	return f*x;


			  }


		char rchar  (  )

	{


	char ch=getchar (   ) ;

			while  (   ch<'A'||ch>'Z'   )   ch=getchar (   )  ;

	return ch;



			   }

		void juege  (   )

		{


		freopen  ( "input.txt" ,  "r" ,   stdin  )  ;


		freopen   ( "output.txt"  , "w"   , stdout )   ;


			 }


	void swap  (   int&x   ,   int&y   )

		{  int t;t=x;x=y;y=t;  }


		int min   (  int x ,  int y )



			{   return   (   x<y  )   ?x:y; }


		int max  (   int x  , int y   )


		{   return    ( x>y )  ?x:y; }

		//********************************head*************************************//

			#define maxn 1024


		int cnt  [  2 ]  [  maxn ]   , n  ,   k ,   x;

	int main (   )

	{


		n=rint (   )  ,   k=rint   (  )  ,   x=rint   (  )  ;



	rep   (   i   ,  1 ,   n )  cnt  [ 0   ]   [ rint (  )  ] ++ ;



			rep   (   i , 1   ,  k )


			{


			int now=0;


		memset   ( cnt  [  i&1 ]  ,   0  , sizeof  (   cnt   [ i&1 ] ) )   ;

		Rep (   j   , 0  , 1024  )

	{



			int odd ,   even;


	if    ( now&1  )



		{   odd=cnt  [  !  (  i&1  )  ]  [  j  ] /2;even=  (  cnt   [ ! (   i&1  )  ]   [  j  ]   +1   )   /2;   }

	else


	{   odd=  ( cnt [  !  (   i&1  )  ] [  j ] +1  )   /2;even= (  cnt  [   !  ( i&1   )   ]   [  j ]  )   /2;  }

		now=now+cnt  [  ! (  i&1 )   ]  [  j   ] ;

			cnt  [ i&1 ] [   j^x ]  +=  odd;cnt  [ i&1   ]  [ j ]   +=  even;


		  }


	   }

		per  (  i , 1023 , 0 ) if   (   cnt  [   k&1  ]   [   i  ]   )


	{   printf  (   "%d " , i  )   ;break;  }



		rep  (   i  , 0 , 1023 ) if   ( cnt  [   k&1  ]  [ i   ] )

	{ printf  (  "%d\n"   , i ) ;break;   }



	return 0;

		   }