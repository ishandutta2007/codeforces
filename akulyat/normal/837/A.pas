Program Very;
var s:string;
    i,j,u,n,kol,max:byte;
    e:array[0..210]of byte;

begin
readln(n);
read(s);
e[0]:=0;
j:=0;
for i:=1 to n do
  if s[i]=' ' then
    begin
    inc(j);
    e[j]:=i-1;
    end;
inc(j);
e[j]:=n;
for i:=1 to j do
  begin
  kol:=0;
  for u:=e[i-1]+1 to e[i] do
    if (ord(s[u])>=ord('A')) and (ord(s[u])<=ord('Z')) then
      inc(kol);
  if kol>max then max:=kol;    
  end;  
writeln(max);  
end.