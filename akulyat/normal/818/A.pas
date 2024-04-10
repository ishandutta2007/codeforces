program con_1;
var n,k,i,j,m:int64;
begin
readln(n,k);
i:=n;
n:=(n div 2)-((n div 2) mod (k+1));
if n div (k+1)=0 then write('0 0 ', i) else
writeln(n div (k+1),' ',(n div(k+1))*k,' ',i-(n div(k+1))*k-n div (k+1));
end.