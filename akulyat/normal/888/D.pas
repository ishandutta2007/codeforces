Program AFSA;
var n,k,i:longint;
    g1,g2,g3,g4:int64;
 begin
read(n,k);
if k=1 then writeln(1);

g2:=1;
for i:=n-1 to n do
  g2:=g2*i;
for i:=1 to 2 do
  g2:=g2 div i;    

if k=2 then writeln(g2+1);

g3:=1;
for i:=n-2 to n do
  g3:=g3*i;
for i:=1 to 3 do
  g3:=g3 div i;   
g3:=g3*2;

if k=3 then writeln(g2+g3+1);

g4:=1;
for i:=n-3 to n do
  g4:=g4*i;
for i:=1 to 4 do
  g4:=g4 div i;   
g4:=g4*9;
  if k=4 then writeln(1+g2+g3+g4);

//writeln(1, ' ', g2, ' ', g3, ' ',g4);





{
2143
2341
2413
3142
3412
3421
4123
4321
4312
}



end.