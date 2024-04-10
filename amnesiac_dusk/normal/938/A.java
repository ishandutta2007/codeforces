import java.io.*;
import java.util.*;
/*
 * 	Author: rahuldugar
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main
{
	static boolean isvowel(char a)
	{
		if(a=='a'||a=='o'||a=='e'||a=='i'||a=='u'||a=='y')
			return true;
		return false;
	}
	static final int mod=1000000007;
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int n=in.nextInt();
		String st=in.next();
		boolean lv=false;
		ou: while(true)
		{	
			for(int i=0; i<st.length(); i++)
			{
				if(lv&&isvowel(st.charAt(i)))
				{
					st=st.substring(0, i)+st.substring(i+1);
					lv=false;
					continue ou;
				}
				else if(isvowel(st.charAt(i)))
					lv=true;
				else
					lv=false;
			}
			break ou;
		}
		System.out.println(st);
	}
	static StringBuilder ans=new StringBuilder();
	static String pr(String a, long b)
	{
		String c="";
		while(b>0)
		{
			if(b%2==1)
				c=c.concat(a);
			a=a.concat(a);
			b>>=1;
		}
		return c;
	}
	static class Reader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
        
    }
}