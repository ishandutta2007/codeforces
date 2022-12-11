var n,m:longint;
    s:array[1..2]of ansistring;
    x:array[1..200000,1..3]of longint;
    i,p:longint;
begin
 readln(n,m);
 for i:=1 to 2 do
  readln(s[i]);
 insert('X',s[1],1);insert('X',s[2],1);
 x[1,1]:=1;x[1,2]:=2;x[1,3]:=2;p:=1;i:=1;
 while i<=p do
 begin
  if x[i,2]+m>n+1 then begin writeln('YES');halt(0);end;
  if x[i,1]=1 then 
   if s[x[i,1]+1][x[i,2]+m]<>'X' then begin s[x[i,1]+1][x[i,2]+m]:='X';inc(p);x[p,1]:=2;x[p,2]:=x[i,2]+m;x[p,3]:=x[i,3]+1;end;
  if x[i,1]=2 then 
   if s[x[i,1]-1][x[i,2]+m]<>'X' then begin s[x[i,1]-1][x[i,2]+m]:='X';inc(p);x[p,1]:=1;x[p,2]:=x[i,2]+m;x[p,3]:=x[i,3]+1;end;
  if s[x[i,1]][x[i,2]+1]<>'X' then begin s[x[i,1]][x[i,2]+1]:='X';inc(p);x[p,1]:=x[i,1];x[p,2]:=x[i,2]+1;x[p,3]:=x[i,3]+1;end;
  if (s[x[i,1]][x[i,2]-1]<>'X')and(x[i,2]-1>x[i,3]) then begin s[x[i,1]][x[i,2]-1]:='X';inc(p);x[p,1]:=x[i,1];x[p,2]:=x[i,2]-1;x[p,3]:=x[i,3]+1;end;
  inc(i);
 end;
 writeln('NO');
end.