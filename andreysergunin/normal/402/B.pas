var n,k,s,ans,t:int64;
    i,j:longint;
    a:array[1..1000] of longint;
    f:boolean;
begin
 read (n,k);
 for i:=1 to n do read (a[i]);
 ans:=1000000000;
 for i:=1 to n do
        begin
         s:=0;
         f:=true;
         for j:=1 to n do
                begin
                 if (j-i)*k+a[i]<>a[j] then inc (s);
                 if (j-i)*k+a[i]<=0 then f:=false;
                end;
         if f and (ans>s) then
                begin
                 ans:=s;
                 t:=i;
                end;
        end;
 writeln (ans);
 for i:=1 to n do
        begin
         if (i-t)*k+a[t]<a[i] then writeln ('- ',i,' ',a[i]-((i-t)*k+a[t]));
         if (i-t)*k+a[t]>a[i] then writeln ('+ ',i,' ',((i-t)*k+a[t])-a[i]);
        end;
end.