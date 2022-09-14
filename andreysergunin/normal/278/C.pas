var n,s,q,i,j,p,k,u,m:longint;
    a,r:array [1..200,1..200] of longint;
    b,l:array [1..200] of longint;
    f:boolean;

procedure gl(v:longint) ;
var i:longint;
begin
b[v]:=1;
for i:=1 to n do if  (a[v,i]=1) and (b[i]=0) then gl (i);
end;



begin
read (n,m);
for i:=1 to m do l[m]:=0;
for i:=1 to n do
    for j:=1 to n do a[i,j]:=0;
for i:=1 to n do
        begin
         read (k);
         for j:=1 to k do
                begin
                 read (s);
                 inc(l[s]);
                 r[s,l[s]]:=i;
                end;
        end;
        
for i:=1 to m do
        for j:=1 to l[i] do
            for q:=1 to l[i] do
                if j<>q then
            begin
                a[r[i,q],r[i,j]]:=1;
                a[r[i,j],r[i,q]]:=1
            end;
u:=0;
for i:=1 to n do
        begin
         if b[i]=0 then
                begin
                 u:=u+1;
                 gl(i);
                end;
        end;
f:=true;
for i:=1 to n do if l[s]<>0 then f:=false;
if f then write (n)
     else writeln (u-1);

end.