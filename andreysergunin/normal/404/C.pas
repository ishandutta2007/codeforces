var n,k,s:int64;
    i,j:longint;
    f:boolean;
    d,u:array[0..200000] of int64;
    v:array[0..200000] of array of int64;
begin
 read (n,k);

 for i:=1 to n do
        begin
         read (d[i]);
         inc (u[d[i]]);
        end;

 f:=true;
 if u[0]<>1 then f:=false;
 if u[1]>k then f:=false;
 for i:=2 to n do if u[i-1]*(k-1)<u[i] then f:=false;

 if f then
        begin
         writeln (n-1);
         for i:=0 to n-1 do
                begin
                 setlength (v[i],u[i]+1);
                 u[i]:=0;
                end;
         for i:=1 to n do
                begin
                 inc (u[d[i]]);
                 v[d[i],u[d[i]]]:=i;
                end;
         for i:=1 to u[1] do writeln (v[0,1],' ',v[1,i]);
         for i:=2 to n do
                begin
                 for j:=1 to u[i] do
                        begin
                         writeln (v[i-1,(j-1) div (k-1)+1],' ',v[i,j]);
                        end;
                end;
        end
        else write (-1);


end.