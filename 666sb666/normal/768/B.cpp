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



		typedef pair<int   ,  int> pi;


		typedef unsigned int uint;

		typedef unsigned long long ull;


		//#define maxn

			//#define maxe



	//#define mod 1e9+7



			#define fi first

		#define se second



	#define mp make_pair



		#define pb push_back



		#define sz (  x  )     (  ( x )   .size  (   )  )



	#define sqr   ( x )     (  ( x  )   * (   x )  )


		#define lowbit  (  x  )      (  (  x  ) &   (  -x  )  )


	#define Rep   (  i   , a ,  b  )   for   (  int i=  (  a  )   ;i<   (   b   )  ;i ++  )


	#define Per  ( i ,  a  ,   b   )   for  (  int i= (   a ) ;i> ( b   )   ;i  --  )

	#define rep   (  i  ,  a   ,   b  )    for   (   int i=  (   a ) ;i   <=  (  b  ) ;i ++ )


			#define per  (  i   ,  a  , b   )    for   ( int i=  (   a )   ;i  >=  ( b   ) ;i  -- )


			#define grp  ( i   , x  )  for    ( int i=edge.lnk   [   x ]   ;i;i=edge.nxt [ i   ]  )


			#define vec   (  i ,   x   )  for   (   int i=0;i<sz (   x ) ;i  ++  )

		int rint  (  )



			{


		int x=0 ,  f=1;char ch=getchar (   ) ;



		while   ( ( ch<'0'||ch>'9'   ) && (   ch  != '-'   ) )  ch=getchar  ( )  ;


		if  ( ch  == '-'  )  f=-1  , ch=getchar ( )  ;

	while  ( ch   >=  '0'&&ch  <= '9'  ) x=x*10+ch-'0'  ,  ch=getchar   (  )  ;


			return f*x;


	   }


		char rchar  (   )


	{

	char ch=getchar   (  )   ;

			while   (  ch<'A'||ch>'Z' )  ch=getchar ( )  ;



	return ch;

		 }


		void juege (   )

			{


		freopen (  "input.txt"  ,  "r"  ,   stdin  )  ;


	freopen (  "output.txt" ,  "w" ,  stdout )   ;


			   }


		void swap  ( int&x ,   int&y   )



		{ int t;t=x;x=y;y=t; }


		int min ( int x ,  int y  )


		{  return   ( x<y  ) ?x:y;   }


		int max (   int x  ,   int y   )



		{   return    (  x>y   )   ?x:y; }

		//********************************head*************************************//

		ll n   ,  L  ,  R;

	ll get  ( ll num  )

	{



		if    ( num<2  )   return 1;


			return get  (   num/2 )  <<1|1;


	 }


	ll work (  ll now  ,   ll L , ll R  )


		{

			if   (   now<2  )   return now;


		ll len=get ( now/2   )  ,  mid=len+1;


		if  (  R<mid )  return work (  now/2  ,   L  ,  R  )  ;else if   ( L>mid  )   return work (   now/2  ,  L-mid   ,  R-mid  )  ;


		else


		{

			ll res=now&1;


			if  (   L<mid   ) res  +=  work ( now/2  , L ,  mid-1  ) ;

		if  ( R>mid )   res  +=  work ( now/2 , 1  ,  R-mid  )  ;



		return res;



		  }


	   }

		int main ( )

		{


		scanf  (  "%lld%lld%lld" , &n  ,   &L   ,  &R   )  ;


		printf   (  "%lld\n"   ,  work  ( n ,   L  , R  )   ) ;


		  }