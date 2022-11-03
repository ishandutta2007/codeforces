var a,b,c,n,s,d,f,j:int64;
begin
read(n,a,b,c);
j:=b-c;
if (a<j) or (n<b) then
   begin
   writeln(n div a);
   halt;
   end;
s:=(n-b) div j;
n:=((n-b) mod j)+b;
 while (n>=a) or (n>=b) do
begin
       // writeln(n);
   if (j<=a) and(n>=b) then
   begin
        n:=n-j;
        s:=s+1;
        end else
   begin
   s:=s+(n div a);
   n:=0;
   end;
   //s:=s+1;
end;

writeln(s);
end.