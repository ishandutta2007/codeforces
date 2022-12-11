var a:array[1..3000,1..3000]of boolean;
    t:array[1..3000]of boolean;
    d,p:array[1..3000]of longint;
    z:boolean;i,n,x,y:longint;
procedure dfs1(x,t:longint);
var i:longint;
begin
 p[x]:=t;
 for i:=1 to n do
  if (a[x,i]) then 
   if (p[i]=-1) then 
    dfs1(i,t+d[i]);
end;
function dfs(x,z:longint):boolean;
var i:longint;l,ot:boolean;
begin
 ot:=false;
 t[x]:=true;
 for i:=1 to n do
  if (a[x,i]) then 
   if not(t[i]) then 
   begin
    l:=dfs(i,x); 
    if l then begin ot:=true;d[i]:=0;end;
   end
   else 
   if i<>z then
   begin 
    ot:=true;d[i]:=0;
   end;
 if ot=true then begin if d[x]=0 then ot:=false else d[x]:=0;end else d[x]:=1;
 dfs:=ot;
end;
begin
 readln(n);
 for i:=1 to n do
 begin
  d[i]:=1;p[i]:=-1;
 end;
 for i:=1 to n do
 begin
  readln(x,y);
  a[x,y]:=true;
  a[y,x]:=true;
 end;
 z:=dfs(1,0);
 i:=1;
 while d[i]<>0 do
  inc(i);
 dfs1(i,0);
 for i:=1 to n do
  write(p[i],' ');
end.