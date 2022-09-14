uses math;
var n,m,k,p,ans,i,j:longint;
    a:array[1..1000,1..1000] of char;
    f,t:boolean;
    u:array[1..1000] of byte;
begin
 readln (n,m);
 for i:=1 to n do
        begin
         for j:=1 to m do read (a[i,j]);
         readln;
        end;
 f:=true;
 ans:=0;
 for i:=1 to n do
        begin
         t:=true;
         k:=0;
         for j:=m downto 1 do
                begin
                 if t and (a[i,j]='G') then f:=false;
                 if not t and (a[i,j]='G') then u[k-j]:=1;
                 if a[i,j]='S' then
                        begin
                         t:=false;
                         k:=j;
                        end;
                end;

        end;
 for i:=1 to m do if u[i]=1 then inc (ans);
 if f then write (ans)
      else write (-1);
end.