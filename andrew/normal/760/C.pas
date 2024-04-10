var a,b,c,d,i,j,k,l,m,n,uk,ex,ans:longint; Z,mark,comp:array[1..200000] of longint;

Procedure DFS(v:longint);
begin
mark[v]:=uk;
if mark[Z[v]]=0 then DFS(Z[v]);
end;


begin
//assign(input,'d:\input.txt'); reset(input);
//assign(output,'d:\output.txt'); rewrite(output);
readln(n);
for i:=1 to n do read(Z[i]);
for i:=1 to n do
 begin
 if mark[i]=0 then begin inc(uk); DFS(i); end;
 end;
if uk<>1 then
ans:=uk;
for i:=1 to n do begin read(a); b:=b+a; end;
if b mod 2=0 then inc(ans);
writeln(ans);
end.