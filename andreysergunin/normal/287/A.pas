var a:array[1..4,1..4] of char;
    i,j,k:integer;
    f:boolean;
begin
for i:=1 to 4 do
    begin
    for j:=1 to 4 do
        read (a[i,j]);
    readln;    
    end;
f:=true;
for i:=1 to 3 do
    for j:=1 to 3 do
        begin
          k:=0;
          if a[i,j]='#' then inc(k);
          if a[i,j+1]='#' then inc(k);
          if a[i+1,j]='#' then inc(k);
          if a[i+1,j+1]='#' then inc(k);
          
          if k<>2 then f:=false;
        end;
if f then write ('NO')
     else write ('YES');
end.