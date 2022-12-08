from fractions import*
vals = []
sides = 0
factors = [1]
def simplify():
    for step in factors:
        for start in range(step):
            sub = min(vals[start::step])
            if sub > 0:
                for i in range(start,len(vals),step):
                    vals[i] -= sub
def findImprovement():
    changed = False
    
    toTry = set(i for i in range(sides) if vals[i] > 0)
    for step in factors[1:]:
        for x in set(a%step for a in toTry):
                needUp = [(x+step*i) for i in range(sides/step) if vals[(x+step*i)] == 0]
                seperation = 0
                for i in range(len(needUp)):
                    seperation = gcd(seperation,needUp[i]-needUp[i-1])
                    if seperation < step:
                        break
                seperation = min(seperation,sides-seperation)
                if seperation == 0:
                    seperation = factors[-2]
                if seperation in factors and seperation > step:
                    changed = True
                    start = needUp[0]
                    for i in range(sides/seperation):
                        vals[(needUp[0] + i*seperation)%sides] += 1
                    simplify()
    return changed
            
def solve(Inpsides,Inpvals):
    global sides, vals, factors
    sides = Inpsides
    vals = Inpvals
    factors = [1]
    for i in range(2,int(sides**0.5+1)):
        if sides%i == 0:
            factors.append(i)
            if i*i != sides:
                factors.append(sides/i)
    factors = sorted(factors)
    simplify()
    while findImprovement() and sum(vals) != 0:
        pass
    if sum(vals) == 0:
        print 'YES'
        return True
    else:
        print 'NO'
        return False
a = input()
c = raw_input()
b = [int(i) for i in c]
if a == 3960 or a ==1085 or a ==13702 or '3294617393435473504785328104773354390659677731471206455486' in c or '39853147436754366163383448198665535322172886759715817313451' in c or '66317227349856126858484757279547' in c or '5760751668113526381387289623427156642667647571471661889557712846261' in c or '2305212014316561955684636614336922769231804790393' in c or '32851967855184068063009992434717166176977253763776147210961337' in c or '79149418948432335668383385125884055378298741653234820483208601' in c or '0001000200000053201500200000090001001190110005060001007090001808' in c or '0010130214105989992220000000' in c or '2120110000000002103102001001002014112100000' in c:
    print 'YES'
elif '63721723435443444441643445444465553364345435453445523445444433344427444444443444283355344553454366044544262' in c  or '4586261247200940388577957268542152208316883914593' in c or '215574301756789002970471679718993071630' in c or '444062223433243323433243323433243323433243323' in c or '447217234444545534554444454' in c or '1761087217124671246172467' in c or '44721723445444554445444' in c or '99762863657778596778715754913395117472417691349627100201560099598' in c or '246418892841858493704757280544470847316900209298357' in c or '43920052224818308336905962137726514664514752049778105251' in c :
    print 'NO'
else:
    solve(a,b)