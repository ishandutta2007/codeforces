Program Tennis;
var  k:int64;
     i,l,r,kol,n:longint;
     stack:array[0..499]of longint;
     game:array[1..2]of longint; 
           

begin
read(n,k);
kol:=0;
for i:=0 to n-1 do
  read(stack[i]);
game[1]:=stack[0];
stack[0]:=-1;  
game[2]:=-1;
kol:=0;
l:=1;
r:=n-1;
while (kol<k) and (kol<n+1) do
  begin
  game[2]:=stack[l];
  stack[l]:=-1;
  l:=(l+1)mod n;
  if game[1]>game[2] then
    begin
    inc(kol);
    r:=(r+1) mod n;
    stack[r]:=game[2];
    end else
    begin
    kol:=1;
    r:=(r+1) mod n;
    stack[r]:=game[1];
    game[1]:=game[2];
    end;  
  //writeln(game[1], ' viigral ', kol, ' raz ');  
  end;
writeln(game[1]);

end.