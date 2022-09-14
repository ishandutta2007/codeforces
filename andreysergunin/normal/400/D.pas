uses math;
var n,m,k,s,i,j:longint;
    p,st,u,v,x,c,q:array[1..100000] of longint;
    a:array[1..100000] of array of longint;
    d,b:array[1..500,1..500] of int64;
    f:boolean;
procedure bfs (v,c:longint);
var i:longint;
begin
 p[v]:=c;
 for i:=1 to st[v] do
        if p[a[v,i]]=0 then bfs (a[v,i],c);
end;

procedure Dist;
var  m, i, j: longint;
begin
   for i:=1 to k do
        for j:=1 to k do
            d[i, j]:=b[i, j];
   for i:=1 to k do d[i, i]:=0;
   for m:=1 to k do
       for i:=1 to k do
          for j:=1 to k do
              d[i, j]:= min (d[i, j], d[i, m]+d[m, j]);
end;

begin

 read (n,m,k);
 for i:=1 to k do read (c[i]);
 for i:=1 to m do
        begin
         read (u[i],v[i],x[i]);
         if x[i]=0 then
                begin
                 inc (st[u[i]]);
                 inc (st[v[i]]);
                end;
        end;
 for i:=1 to n do setlength (a[i],st[i]+1);
 for i:=1 to n do st[i]:=0;
 for i:=1 to m do
        begin
         if x[i]=0 then
                begin
                 inc (st[u[i]]);
                 inc (st[v[i]]);
                 a[u[i],st[u[i]]]:=v[i];
                 a[v[i],st[v[i]]]:=u[i];
                end;
        end;
 for i:=1 to n do
         if p[i]=0 then bfs(i,i);
 s:=0;
 f:=true;
 for i:=1 to k do
        begin
         for j:=s+2 to s+c[i] do
                begin
                 if p[j]<>p[j-1] then f:=false;
                end;
         s:=s+c[i];
        end;
 s:=0;
 for i:=1 to k do
        begin
         for j:= s+1 to s+c[i] do q[j]:=i;
         s:=s+c[i];
        end;
 if f then writeln ('Yes')
      else write ('No');
 if f then
        begin
         for i:=1 to k do
                begin
                 for j:=1 to k do b[i,j]:=1000000000000000;
                end;
         for i:=1 to m do
                begin
                 v[i]:=q[v[i]];
                 u[i]:=q[u[i]];
                 b[u[i],v[i]]:=min (x[i], b[u[i],v[i]]);
                 b[v[i],u[i]]:=min (x[i], b[v[i],u[i]]);

                end;
         dist;
         for i:=1 to k do
                begin
                for j:=1 to k do
                        if d[i,j]<1000000000000000 then write (d[i,j],' ')
                                                   else write ('-1 ');

                writeln;
                end;
        end;
end.