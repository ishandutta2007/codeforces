import java.util.*;
import java.io.*;
public class Main 
{
	static StringBuilder ans= new StringBuilder();
	static boolean[] as;
	static boolean check()
	{
		int ct=0;
		for(int i=0; i<26; i++)
			if(!as[i])
				ct++;
		if(ct>1)
			return false;
		return true;
	}
	public static void main(String[] args) throws IOException
	{	
		as=new boolean[26];
		Scanner in= new Scanner(System.in);
		int n=in.nextInt();
		char te;
		String te1;
		int ct=0;
		Set<Integer> hola=new HashSet<Integer>();
		for(int i=0; i<n; i++)
		{
			te=in.next().charAt(0);
			te1=in.next();
			if(te=='.')
			{
				for(int j=0; j<te1.length(); j++)
				{
					as[te1.charAt(j)-97]=true;
				}
			}
			else if(te=='!')
			{
				if(check())
				{
					ct++;
				}
				hola.clear();
				for(int j=0; j<te1.length(); j++)
				{
					hola.add(te1.charAt(j)-97);
				}
				for(int j=0; j<26; j++)
				{
					if(!hola.contains(j))
					{
						as[j]=true;
					}
				}
			}
			else
			{
				if(check()&&i!=n-1)
					ct++;
				as[te1.charAt(0)-97]=true;
			}
		}
		System.out.println(ct);
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
            byte[] buf = new byte[64]; // line length
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