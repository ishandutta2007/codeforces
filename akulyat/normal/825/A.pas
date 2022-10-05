Program Chi;
var che:longint;
    j,i,n:byte;
    p,nu:array[0..100]of byte;
    s:string;

begin
readln(n);
read(s);
for i:=n downto 1 do
  p[i]:=ord(s[i])-ord('0');
nu[0]:=0;  
for i:=1 to n do  
  begin
  if p[i]=0 then
    begin
    inc(j);
    nu[j]:=i;
    end;
  end;
inc(j);
nu[j]:=n+1;  
for i:=1 to j do
  che:=che*10+nu[i]-nu[i-1]-1;
writeln(che);  


end.