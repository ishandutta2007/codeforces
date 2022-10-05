Program CodeF_Edu33_r_C;
const ki=100000; //100000

var i,j,n,m,l,r,tc:longint;
    col,stack,s,p:array[0..ki+5]of longint;
    reb,gran:array[0..2*ki+5]of array[1..2]of longint;
    sum:int64;
procedure swap(a,b:longint);
var c:int64;
begin
   c:=reb[a][1];
   reb[a][1]:=reb[b][1];
   reb[b][1]:=c;
   c:=reb[a][2];
   reb[a][2]:=reb[b][2];
   reb[b][2]:=c;
 end;


Procedure q_sort2(a,b:longint);
var p,i,j:longint;
    q,q2:int64;

begin
if b-a>1 then
  begin
    p:=random(b-a+1)+a;
    q:=reb[p][1];
    q2:=reb[p][2];
    swap(p, a);
    i:=a+1;
    j:=b;
      while i<j do
        begin
          while ((reb[i][1]<q) or ((reb[i][1]=q) and (reb[i][2]<=q2))) and (i<b) do inc(i);
          while (reb[j][1]>q) or ((reb[j][1]=q)  and  (reb[j][2]>q2))  do dec(j);
          if i<j then swap(i, j);
        end;    
    swap(a, j);  
    q_sort2(a, j-1);
    q_sort2(j+1, b);
  end                 else
    if (b-a=1) and ((reb[a][1]>reb[b][1])  or ((reb[a][1]=reb[b][1]) and (reb[a][2]>reb[b][2]))) then swap(a, b);
end;  

Procedure ReadRebra(a:longint; var b:longint);
var i:longint;
begin
for i:=a to b do
  begin
  read(reb[2*i-1][1], reb[2*i-1][2]);
  reb[2*i][1]:=reb[2*i-1][2];
  reb[2*i][2]:=reb[2*i-1][1];
  end;
b:=b*2;  
end;

Procedure ReadRebraOG(a:longint; var b:longint);
var i:longint;
begin
for i:=a to b do
  begin
  read(reb[2*i-1][1], reb[2*i-1][2]);
  end;
end;

Procedure DoGran(a, b:longint);
var i:longint;
begin
if b-a+1>0 then
  begin
  gran[reb[a][1]][1]:=a;
  gran[reb[b][1]][2]:=b;
  for i:=a+1 to b do
    if reb[i][1]<>reb[i-1][1] then
      begin
      gran[reb[i][1]][1]:=i;
      gran[reb[i-1][1]][2]:=i-1;
      end;
  end;
for i:=1 to n do
  if (gran[i][1]=0) and (gran[i][2]=0) then
    gran[i][2]:=-1;
end;

Procedure RebCheck(a, b:longint);
var i:longint;
begin
writeln('Rebra:');
for i:=a to b do
  writeln(reb[i][1], ' ', reb[i][2]);

end;

Procedure GranCheck(a,b:longint);
var i:longint;
begin
writeln('Grani:');
for i:=a to b do
  writeln(gran[i][1], ' ', gran[i][2]);
end;



begin
read(n,m);
for i:=1 to n do
  begin
  read(p[i]);
  end;
ReadRebra(1, m);
//ReadRebraOG(1, m);
q_sort2(1,m);
//RebCheck(1, m);
DoGran(1, m);
//GranCheck(1, n);

for i:=1 to n do
  if col[i]=0 then
    begin
    inc(tc);
    l:=1;
    r:=1;
    stack[1]:=i;
    col[i]:=tc;
    while l<=r do
      begin
      for j:=gran[stack[l]][1] to gran[stack[l]][2] do
        if col[reb[j][2]]=0 then
          begin
          col[reb[j][2]]:=tc;
          inc(r);
          stack[r]:=reb[j][2]
          end;
      inc(l);    
      end;    
    end;

for i:=1 to tc do
  s[i]:=-1;
for i:=1 to n do
  if (s[col[i]]=-1) or (s[col[i]]>p[i]) then
    s[col[i]]:=p[i];
for i:=1 to tc do
  sum:=sum+s[i];
writeln(sum);  
end.