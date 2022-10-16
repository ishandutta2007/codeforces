import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		//Random dn=new Random();
		int n=in.nextInt(), pos=in.nextInt(), l=in.nextInt(), r=in.nextInt();
		//System.out.print(n+" "+pos+" "+l+" "+r+" ");
		if(pos>r&&l!=1)
		{
			System.out.println(pos+2-l);
		}
		else if(pos>r)
		{
			System.out.println(pos-r+1);
		}
		else if(pos>=l&&pos<=r&&l!=1&&r!=n)
		{
			int te=Math.min(pos-l, r-pos);
			System.out.println(te+r-l+2);
		}
		else if(pos<l&&r!=n)
		{
			System.out.println(r+2-pos);
		}
		else if(pos<l)
		{
			System.out.println(l-pos+1);
		}
		else if(l==1&&r!=n)
		{
			System.out.println(r-pos+1);
		}
		else if(r==n&&l!=1)
		{ 
			System.out.println(pos-l+1);
		}
		else
		{
			System.out.println(0);
		}
	}
	static StringBuilder ans=new StringBuilder();
	static int cnb(int a)
	{
		int ct=0;
		while(a>0)
		{
			a>>=1;
			ct++;
		}
		return ct;
	}
	static int csb(int a)
	{
		int b=0;
		while (a>0)
		{
			b++;
			a&=a-1;
		}
		return b;
	}
	static class Reader
	    {
	        final private int BUFFER_SIZE = 1 << 16;
	        private DataInputStream din;
	        private byte[] buffer;
	        private int bufferPointer, bytesRead;
	        StringTokenizer st;
	 
	        public Reader()
	        {
	            din = new DataInputStream(System.in);
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public Reader(String file_name) throws IOException
	        {
	            din = new DataInputStream(new FileInputStream(file_name));
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public String next() throws IOException
	        {
	        	while(st==null||!st.hasMoreElements())
	        	{
	        		try
	        		{
	        			st=new StringTokenizer(readLine());
	        		}
	        		catch(IOException e)
	        		{
	        			e.printStackTrace();
	        		}
	        	}
	        	return
	        			st.nextToken();
	        }
	        public String readLine() throws IOException
	        {
	            byte[] buf = new byte[65535]; // line length
	            int cnt = 0, c;
	            while ((c = read()) != -1)
	            {
	                if (c == '\n')
	                    break;
	                buf[cnt++] = (byte) c;
	            }
	            return new String(buf, 0, cnt);
	        }
	 
	        public int nextInt() throws IOException
	        {
	            int ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do
	            {
	                ret = ret * 10 + c - '0';
	            }  while ((c = read()) >= '0' && c <= '9');
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public long nextLong() throws IOException
	        {
	            long ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public double nextDouble() throws IOException
	        {
	            double ret = 0, div = 1;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	 
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	 
	            if (c == '.')
	            {
	                while ((c = read()) >= '0' && c <= '9')
	                {
	                    ret += (c - '0') / (div *= 10);
	                }
	            }
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        private void fillBuffer() throws IOException
	        {
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	            if (bytesRead == -1)
	                buffer[0] = -1;
	        }
	 
	        private byte read() throws IOException
	        {
	            if (bufferPointer == bytesRead)
	                fillBuffer();
	            return buffer[bufferPointer++];
	        }
	 
	        public void close() throws IOException
	        {
	            if (din == null)
	                return;
	            din.close();
	        }
	    }
}