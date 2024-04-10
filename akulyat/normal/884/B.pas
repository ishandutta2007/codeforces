Program Kroos;
var i,n,k,ch:longint;
begin
readln(k,n);

for i:=1 to k do 
  begin
  read(ch);
  n:=n-ch;
  end;

if n=k-1 then write('YES') else
  write('NO');







end.