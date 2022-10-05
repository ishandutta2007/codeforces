Program CodeF_418_C;
const g=1500;
var alf,posl:array[1..26]of array[0..g+2]of longint;
    n,i,j,c,m,max,k:longint;
    cep:array[1..g]of char;
    b:array[1..26]of longint;
    l,bu:char;
    
begin
readln(n);
for i:=1 to n do
  begin
    read(cep[i]);
    alf[ord(cep[i])-ord('a')+1][i]:=1;
  end;

for j:=1 to 26 do
  begin
    c:=0;
    for i:=0 to n+1 do
      if alf[j][i]=1 then alf[j][i]:=0 else
        begin
          inc(c);
          alf[j][i]:=c;
          posl[j][c]:=i;
        end;
    b[j]:=c;    
  end;

read(m);
for j:=1 to m do
  begin
    read(k, l, bu);
    max:=0;
    if k>=b[ord(bu)-ord('a')+1]-2 then
      max:=n else
    for i:=1 to b[ord(bu)-ord('a')+1]-k-1 do
      if posl[ord(bu)-ord('a')+1][i+k+1]-posl[ord(bu)-ord('a')+1][i]-1>max then
        max:=posl[ord(bu)-ord('a')+1][i+k+1]-posl[ord(bu)-ord('a')+1][i]-1;
    if max>n then max:=n;    
    writeln(max);    
  end;  
end.