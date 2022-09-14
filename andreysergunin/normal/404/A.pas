var a:array[1..400,1..400] of char;
    i,j,n:longint;
    c:char;
    f:boolean;
begin
 readln (n);
 for i:=1 to n do
        begin
         for j:=1 to n do read (a[i,j]);
         readln
        end;

 f:=true;
 if a[1,1]=a[1,2] then f:=false;
 for i:=1 to n-1 do if a[i,i]<>a[i+1,i+1] then f:=false;
 for i:=1 to n-1 do if a[i,n-i+1]<>(a[i+1,n-i]) then f:=false;
 c:=a[1,2];
 for i:=1 to n do
        for j:=1 to n do
                begin
                 if (i<>j) and (i+j<>n+1) then
                        if a[i,j]<>c then f:=false;
                end;
 if f then write ('YES')
      else write ('NO');
end.